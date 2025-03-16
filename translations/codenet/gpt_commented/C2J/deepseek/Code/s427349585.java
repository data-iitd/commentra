import java.util.Scanner;

class Card {
    char s;
    int v;

    Card(char s, int v) {
        this.s = s;
        this.v = v;
    }
}

public class Main {
    // Arrays to hold the left and right halves during merge sort
    static Card[] L = new Card[100000 / 2 + 2];
    static Card[] R = new Card[100000 / 2 + 2];

    // Merge function to combine two sorted halves of the array
    static void merge(Card[] a, int n, int l, int m, int r) {
        int i, j, k;
        int n1 = m - l; // Size of the left half
        int n2 = r - m; // Size of the right half

        // Copy data to temporary arrays L and R
        for (i = 0; i < n1; i++) L[i] = a[l + i];
        for (i = 0; i < n2; i++) R[i] = a[m + i];

        // Sentinel values to avoid out-of-bounds access
        L[n1] = new Card(' ', 2000000000);
        R[n2] = new Card(' ', 2000000000);

        // Merge the temporary arrays back into the original array
        i = 0; // Index for left array
        j = 0; // Index for right array
        for (k = l; k < r; k++) {
            if (L[i].v <= R[j].v) {
                a[k] = L[i++]; // Take from left if it's smaller or equal
            } else {
                a[k] = R[j++]; // Take from right otherwise
            }
        }
    }

    // Merge sort function to recursively sort the array
    static void mergeSort(Card[] a, int n, int l, int r) {
        if (l + 1 < r) { // Base case: if the segment has more than one element
            int m = (l + r) / 2; // Find the midpoint
            mergeSort(a, n, l, m); // Sort the left half
            mergeSort(a, n, m, r); // Sort the right half
            merge(a, n, l, m, r); // Merge the sorted halves
        }
    }

    // Partition function for quicksort
    static int partition(Card[] a, int n, int p, int r) {
        Card x = a[r]; // Choose the last element as the pivot
        int i = p - 1; // Index of smaller element
        for (int j = p; j < r; j++) {
            if (a[j].v <= x.v) { // If current element is smaller than or equal to pivot
                i++; // Increment index of smaller element
                // Swap elements
                Card t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        // Swap the pivot element with the element at i + 1
        Card t = a[i + 1];
        a[i + 1] = a[r];
        a[r] = t;
        return i + 1; // Return the partitioning index
    }

    // Quicksort function to recursively sort the array
    static void quickSort(Card[] a, int n, int p, int r) {
        if (p < r) { // Base case: if the segment has more than one element
            int q = partition(a, n, p, r); // Partition the array
            quickSort(a, n, p, q - 1); // Recursively sort the left half
            quickSort(a, n, q + 1, r); // Recursively sort the right half
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Card[] a = new Card[200000];
        Card[] b = new Card[200000];

        // Read the cards into both arrays a and b
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            int v = scanner.nextInt();
            a[i] = new Card(s.charAt(0), v);
            b[i] = new Card(s.charAt(0), v);
        }

        // Perform merge sort on array a
        mergeSort(a, n, 0, n);
        // Perform quicksort on array b
        quickSort(b, n, 0, n - 1);

        // Check if the sorting is stable by comparing the original and sorted arrays
        boolean stable = true;
        for (int i = 0; i < n; i++) {
            if (a[i].s != b[i].s) {
                stable = false; // If any character differs, it's not stable
                break;
            }
        }

        // Output the stability result
        if (stable) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }

        // Print the sorted array
        for (int i = 0; i < n; i++) {
            System.out.println(b[i].s + " " + b[i].v);
        }

        scanner.close();
    }
}

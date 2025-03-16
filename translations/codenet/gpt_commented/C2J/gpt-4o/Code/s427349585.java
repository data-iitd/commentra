import java.util.Scanner;

// Define a class to represent a card with a character and an integer value
class Card {
    char s; // Character representing the card's suit or type
    int v;  // Integer representing the card's value

    Card(char s, int v) {
        this.s = s;
        this.v = v;
    }
}

public class CardSorting {
    // Arrays to hold the left and right halves during merge sort
    static Card[] L = new Card[100000 / 2 + 2];
    static Card[] R = new Card[100000 / 2 + 2];

    // Merge function to combine two sorted halves of the array
    static void merge(Card[] a, int l, int m, int r) {
        int n1 = m - l; // Size of the left half
        int n2 = r - m; // Size of the right half

        // Copy data to temporary arrays L and R
        for (int i = 0; i < n1; i++) L[i] = a[l + i];
        for (int i = 0; i < n2; i++) R[i] = a[m + i];

        // Sentinel values to avoid out-of-bounds access
        L[n1] = new Card('\0', 2000000000);
        R[n2] = new Card('\0', 2000000000);

        // Merge the temporary arrays back into the original array
        int i = 0; // Index for left array
        int j = 0; // Index for right array
        for (int k = l; k < r; k++) {
            if (L[i].v <= R[j].v) {
                a[k] = L[i++]; // Take from left if it's smaller or equal
            } else {
                a[k] = R[j++]; // Take from right otherwise
            }
        }
    }

    // Merge sort function to recursively sort the array
    static void mergeSort(Card[] a, int l, int r) {
        if (l + 1 < r) { // Base case: if the segment has more than one element
            int m = (l + r) / 2; // Find the midpoint
            mergeSort(a, l, m); // Sort the left half
            mergeSort(a, m, r); // Sort the right half
            merge(a, l, m, r); // Merge the sorted halves
        }
    }

    // Partition function for quicksort
    static int partition(Card[] a, int p, int r) {
        Card x = a[r]; // Choose the last element as the pivot
        int i = p - 1; // Index of smaller element
        for (int j = p; j < r; j++) {
            if (a[j].v <= x.v) { // If current element is smaller than or equal to pivot
                i++; // Increment index of smaller element
                // Swap elements
                Card temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        // Swap the pivot element with the element at i + 1
        Card temp = a[i + 1];
        a[i + 1] = a[r];
        a[r] = temp;
        return i + 1; // Return the partitioning index
    }

    // Quicksort function to recursively sort the array
    static void quickSort(Card[] a, int p, int r) {
        if (p < r) { // Base case: if the segment has more than one element
            int q = partition(a, p, r); // Partition the array
            quickSort(a, p, q - 1); // Recursively sort the left half
            quickSort(a, q + 1, r); // Recursively sort the right half
        }
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Card[] a = new Card[200000]; // Array to hold the cards for sorting
        Card[] b = new Card[200000]; // Array to hold the cards for sorting
        int stable = 1; // Flag to check if the sorting is stable

        // Read the cards into both arrays a and b
        for (int i = 0; i < n; i++) {
            char s = scanner.next().charAt(0);
            int v = scanner.nextInt();
            a[i] = new Card(s, v);
            b[i] = new Card(s, v);
        }

        // Perform merge sort on array a
        mergeSort(a, 0, n);
        // Perform quicksort on array b
        quickSort(b, 0, n - 1);

        // Check if the sorting is stable by comparing the original and sorted arrays
        for (int i = 0; i < n; i++) {
            if (a[i].s != b[i].s) {
                stable = 0; // If any character differs, it's not stable
            }
        }

        // Output the stability result
        if (stable == 1) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }

        // Print the sorted array
        for (int i = 0; i < n; i++) {
            System.out.println(b[i].s + " " + b[i].v);
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>

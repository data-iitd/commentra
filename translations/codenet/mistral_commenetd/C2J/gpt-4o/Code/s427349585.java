import java.util.Scanner;

// Define a custom data structure 'Card' with a character and an integer.
class Card {
    char s;
    int v;

    Card(char s, int v) {
        this.s = s;
        this.v = v;
    }
}

public class Main {
    // Allocate memory for two arrays L and R, each with size (n+2), where n is the number of input cards.
    static Card[] L = new Card[100000 / 2 + 2];
    static Card[] R = new Card[100000 / 2 + 2];

    // Function 'me' sorts a subarray of 'a' using merge sort algorithm.
    static void me(Card[] a, int n, int l, int m, int r) {
        int n1 = m - l; // Number of elements to be copied to L array.
        int n2 = r - m; // Number of elements to be copied to R array.

        // Copy elements from 'a' to L and R arrays.
        for (int i = 0; i < n1; i++) L[i] = a[l + i];
        for (int i = 0; i < n2; i++) R[i] = a[m + i];

        // Set the last elements of L and R arrays with a large value to mark the end of each array.
        L[n1] = new Card('\uFFFF', 2000000000); // Using a large character value
        R[n2] = new Card('\uFFFF', 2000000000); // Using a large character value

        // Merge sorted subarrays L and R back to 'a'.
        int i = 0, j = 0;
        for (int k = l; k < r; k++) {
            // Compare elements from L and R arrays and copy smaller one to 'a'.
            if (L[i].v <= R[j].v) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
            }
        }
    }

    // Recursive function 'ms' to merge sort the entire array 'a'.
    static void ms(Card[] a, int n, int l, int r) {
        if (l + 1 < r) {
            int m = (l + r) / 2;
            // Recursively sort left and right subarrays and then merge them.
            ms(a, n, l, m);
            ms(a, n, m, r);
            // Merge sorted subarrays.
            me(a, n, l, m, r);
        }
    }

    // Function 'partition' partitions an array into two parts.
    static int partition(Card[] a, int n, int p, int r) {
        Card x = a[r]; // Set 'x' as the last element of the array.
        int i = p - 1; // Index of the last element in the left subarray.

        // Iterate through the array from index p to r-1 and swap elements if they are smaller than 'x'.
        for (int j = p; j < r; j++) {
            if (a[j].v <= x.v) {
                i++; // Increment index of the last element in the left subarray.
                Card t = a[i]; // Swap elements a[i] and a[j].
                a[i] = a[j];
                a[j] = t;
            }
        }
        // Swap the last elements of the left and right subarrays.
        Card t = a[i + 1];
        a[i + 1] = a[r];
        a[r] = t;
        // Return the index 'i+1' as the pivot index.
        return i + 1;
    }

    // Function 'qs' implements quicksort algorithm to sort the array 'a'.
    static void qs(Card[] a, int n, int p, int r) {
        if (p < r) {
            int q = partition(a, n, p, r);
            // Recursively sort the left and right subarrays.
            qs(a, n, p, q - 1);
            qs(a, n, q + 1, r);
        }
    }

    // Main function to read input, sort the array using merge sort and quicksort, and print the sorted array.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Card[] a = new Card[200000];
        Card[] b = new Card[200000];
        int stable = 1;

        // Read input cards and initialize 'a' and 'b' arrays.
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            int v = scanner.nextInt();
            a[i] = new Card(s.charAt(0), v);
            b[i] = new Card(s.charAt(0), v);
        }

        // Merge sort the 'a' array.
        ms(a, n, 0, n);

        // Quick sort the 'b' array.
        qs(b, n, 0, n - 1);

        // Compare 'a' and 'b' arrays to check stability.
        for (int i = 0; i < n; i++) {
            if (a[i].s != b[i].s) {
                stable = 0;
            }
        }
        // Print the result and the sorted array 'b'.
        if (stable == 1) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }
        // Print the sorted array 'b'.
        for (int i = 0; i < n; i++) {
            System.out.println(b[i].s + " " + b[i].v);
        }

        scanner.close();
    }
}
// <END-OF-CODE>

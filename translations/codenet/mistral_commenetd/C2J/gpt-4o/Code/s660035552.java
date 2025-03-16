import java.util.Scanner; // Import Scanner for input

public class Main {
    // Initialize low and high arrays for quicksort
    static int[] low = new int[200000];
    static int[] high = new int[200000];

    // Array 'a' to store elements after sorting
    static int[] a = new int[200000];

    // Array 'b' to store elements for quicksort partitioning
    static int[] b = new int[200000];

    // Function to partition the array using quicksort algorithm
    static int part(int[] a, int[] b, int l, int r) {
        int i = l - 1; // Initialize index 'i' for smaller elements
        int j = r; // Initialize index 'j' for greater elements
        int x = b[r]; // Set pivot as last element

        while (true) { // While loop for partitioning
            while (b[++i] < x); // Move 'i' to next smaller element
            while (i < --j && x < b[j]); // Move 'j' to previous greater element

            if (i >= j) break; // If 'i' and 'j' meet, partitioning is done

            // Swap elements in 'a' array
            int t = a[i];
            a[i] = a[j];
            a[j] = t;

            // Swap elements in 'b' array
            t = b[i];
            b[i] = b[j];
            b[j] = t;
        }

        // Swap pivot with last element in 'a' array
        int t = a[i];
        a[i] = a[r];
        a[r] = t;

        // Swap pivot with last element in 'b' array
        t = b[i];
        b[i] = b[r];
        b[r] = t;

        return i; // Return index of pivot
    }

    // Function to perform quicksort on the array 'a'
    static void quicksort(int[] a, int[] b, int n) {
        int sp = 0; // Stack pointer
        low[sp] = 0; // Initialize 'low' stack with base index 0
        high[sp] = n - 1; // Initialize 'high' stack with top index 'n-1'
        sp++; // Increment stack pointer

        while (sp > 0) { // While stack is not empty
            sp--; // Decrement stack pointer
            int l = low[sp]; // Get base index 'l' from stack
            int r = high[sp]; // Get top index 'r' from stack

            if (l >= r) { // If base and top indices are same, no need to partition
                continue; // Skip this iteration
            }

            int v = part(a, b, l, r); // Partition the array

            if (v - l < r - v) { // If partitioning moved pivot to left
                low[sp] = v + 1;
                high[sp++] = r;
                low[sp] = l;
                high[sp++] = v - 1;
            } else { // If partitioning moved pivot to right
                low[sp] = l;
                high[sp++] = v - 1;
                low[sp] = v + 1;
                high[sp++] = r;
            }
        }
    }

    // Main function to read input and call quicksort
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create scanner for input
        int n, m; // Initialize variables
        int cnt = 0; // Initialize counter for unique elements

        n = scanner.nextInt(); // Read number of elements 'n'
        m = scanner.nextInt(); // Read number of queries 'm'

        for (int i = 0; i < m; i++) {
            a[i] = scanner.nextInt(); // Read elements
            b[i] = scanner.nextInt(); // Read corresponding queries
        }

        quicksort(a, b, m); // Call quicksort function to sort elements

        int t = 0; // Initialize counter to 0
        for (int i = 0; i < m; i++) { // Iterate through sorted elements
            if (t <= a[i]) { // If current element is greater than previous element
                t = b[i]; // Set current query as new temporary storage
                cnt++; // Increment counter
            }
        }

        System.out.println(cnt); // Print the number of unique queries
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>

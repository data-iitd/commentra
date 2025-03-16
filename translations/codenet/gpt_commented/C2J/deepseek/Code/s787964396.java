public class CountingSort {
    public static void main(String[] args) {
        int[] a, b;
        int i, max = 0, n;

        // Read the number of elements to be sorted
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Allocate memory for the input array 'a' and output array 'b'
        a = new int[n + 1];
        b = new int[n + 1];

        // Read 'n' elements into the array 'a'
        for (i = 0; i < n; i++) {
            a[i + 1] = scanner.nextInt(); // Store elements starting from index 1
        }

        // Call the CountingSort function to sort the array 'a' and store the result in 'b'
        CountingSort(a, b, n);

        // Print the sorted elements from array 'b'
        System.out.print(b[1]); // Print the first sorted element
        for (i = 2; i < n + 1; i++) {
            System.out.print(" " + b[i]); // Print the remaining sorted elements
        }
        System.out.println();

        // Free the allocated memory for arrays 'a' and 'b'
        a = null;
        b = null;
    }

    // Function to perform Counting Sort
    public static void CountingSort(int[] a, int[] b, int k) {
        int[] c = new int[10000];
        int i, j;

        // Initialize the counting array 'c' to zero
        for (i = 0; i < 10000; i++) {
            c[i] = 0; // Set all counts to zero
        }

        // Count occurrences of each element in array 'a'
        for (j = 0; j < k; j++) {
            c[a[j + 1]]++; // Increment the count for each element
        }

        // Update the counting array 'c' to contain the actual positions of elements
        for (i = 1; i < 10001; i++) {
            c[i] += c[i - 1]; // Cumulative sum to determine positions
        }

        // Build the output array 'b' using the counting array 'c'
        for (j = k; j > 0; j--) {
            b[c[a[j]]] = a[j]; // Place the elements in their sorted position
            c[a[j]]--; // Decrement the count for the current element
        }
    }
}

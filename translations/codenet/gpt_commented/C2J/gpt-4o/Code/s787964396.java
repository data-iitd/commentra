import java.util.Scanner;

public class CountingSort {
    static final int I = 10000; // Define a constant for the maximum range of input values

    // Function to perform Counting Sort
    public static void countingSort(int[] a, int[] b, int k) {
        int[] c = new int[I + 1]; // Counting array

        // Initialize the counting array 'c' to zero
        for (int i = 0; i <= I; i++) {
            c[i] = 0; // Set all counts to zero
        }

        // Count occurrences of each element in array 'a'
        for (int j = 0; j < k; j++) {
            c[a[j + 1]]++; // Increment the count for each element
        }

        // Update the counting array 'c' to contain the actual positions of elements
        for (int i = 1; i <= I; i++) {
            c[i] += c[i - 1]; // Cumulative sum to determine positions
        }

        // Build the output array 'b' using the counting array 'c'
        for (int j = k; j > 0; j--) {
            b[c[a[j]]] = a[j]; // Place the elements in their sorted position
            c[a[j]]--; // Decrement the count for the current element
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements to be sorted
        int n = scanner.nextInt();
        
        // Allocate memory for the input array 'a' and output array 'b'
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];

        // Read 'n' elements into the array 'a'
        for (int i = 0; i < n; i++) {
            a[i + 1] = scanner.nextInt(); // Store elements starting from index 1
        }

        // Call the countingSort function to sort the array 'a' and store the result in 'b'
        countingSort(a, b, n);

        // Print the sorted elements from array 'b'
        System.out.print(b[1]); // Print the first sorted element
        for (int i = 2; i < n + 1; i++) {
            System.out.print(" " + b[i]); // Print the remaining sorted elements
        }
        System.out.println();

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>

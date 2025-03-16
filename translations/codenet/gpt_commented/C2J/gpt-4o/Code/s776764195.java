import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class CountingSort {
    // Define constants for maximum sizes
    static final int MAX_N = 2000001; // Maximum number of elements
    static final int MAX_Ai = 10001;  // Maximum value of elements

    // Global arrays for input and output
    static int[] A = new int[MAX_N]; // Array to hold input numbers
    static int[] B = new int[MAX_N]; // Array to hold sorted numbers

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder output = new StringBuilder(); // StringBuilder for output

        // Read the number of elements
        int n = Integer.parseInt(reader.readLine().trim());

        // Read each number into the array A
        String[] inputNumbers = reader.readLine().trim().split(" ");
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(inputNumbers[i]);
        }

        // Perform counting sort on the array A and store the result in B
        CountingSort(A, B, MAX_Ai, n);

        // Write the sorted numbers to the output string
        for (int i = 0; i < n; i++) {
            output.append(B[i]);
            if (i < n - 1) {
                output.append(' '); // Append a space after each number
            }
        }

        // Output the final result
        System.out.println(output.toString());
    }

    // Counting sort algorithm implementation
    static void CountingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[k]; // Count array initialized to zero

        // Count occurrences of each number in A
        for (int j = 0; j < len; j++) {
            C[A[j]]++; // Increment count for each number
        }

        // Update count array to hold the position of each number
        for (int i = 1; i < k; i++) {
            C[i] += C[i - 1]; // C[i] now contains the position
        }

        // Build the output array B using the count array
        for (int j = len - 1; j >= 0; j--) {
            B[C[A[j]] - 1] = A[j]; // Place the number in the correct position
            C[A[j]]--; // Decrement the count for the number
        }
    }
}

// <END-OF-CODE>

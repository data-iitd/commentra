import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CountingSort {
    private static final int MAX_N = 2000001;
    private static final int MAX_Ai = 10001;
    
    private static int[] A = new int[MAX_N]; // Input array
    private static int[] B = new int[MAX_N]; // Output array

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder output = new StringBuilder();
        
        String input = reader.readLine(); // Read input into a string
        String[] numbers = input.split(" "); // Split input into numbers
        
        int n = Integer.parseInt(numbers[0]); // Get the number of elements
        for (int i = 1; i <= n; ++i) {
            A[i] = Integer.parseInt(numbers[i]); // Read each element into the array A
        }
        
        CountingSort(A, B, MAX_Ai, n); // Sort the array A using Counting Sort
        
        for (int i = 1; i < n; ++i) {
            output.append(B[i]).append(" "); // Write each sorted element with a space
        }
        output.append(B[n]); // Write the last element without a space
        
        System.out.println(output.toString()); // Output the sorted string
    }

    private static void CountingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[MAX_Ai]; // Initialize count array
        for (int j = 1; j <= len; ++j) {
            ++C[A[j]]; // Count occurrences of each element
        }
        for (int i = 1; i <= k; ++i) {
            C[i] += C[i - 1]; // Calculate cumulative count
        }
        for (int j = len; j > 0; --j) {
            B[C[A[j]]] = A[j]; // Place elements in sorted order
            --C[A[j]]; // Decrement count for the element
        }
    }
}

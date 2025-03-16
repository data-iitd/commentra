import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class CountingSortExample {
    private static final int MAX_N = 2000001; // Maximum number of integers to be read
    private static final int MAX_Ai = 10001;   // Maximum value of an integer
    private static final int STR_SIZE = 10000010; // Size of the input string

    private static int[] A = new int[MAX_N]; // Array to store the input integers
    private static int[] B = new int[MAX_N]; // Array to store the sorted integers
    private static StringBuilder str = new StringBuilder(STR_SIZE); // Buffer to store the input string

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        
        int n; // Variable to store the number of integers to be read
        // Read the number of integers (n) from input
        n = Integer.parseInt(reader.readLine().trim());

        // Read the integers into array A
        String[] input = reader.readLine().trim().split(" ");
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(input[i]);
        }

        // Perform counting sort
        CountingSort(A, B, MAX_Ai, n);

        // Write the sorted integers to output
        for (int i = 0; i < n; i++) {
            putNum(B[i], writer);
        }

        writer.flush();
        writer.close();
    }

    private static void putNum(int n, PrintWriter writer) {
        writer.print(n + " "); // Write an integer to the output
    }

    private static void CountingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[k + 1]; // Create a count array

        // Count occurrences of each integer
        for (int i = 0; i < len; i++) {
            C[A[i]]++;
        }

        // Update count array C to contain actual positions
        for (int i = 1; i <= k; i++) {
            C[i] += C[i - 1];
        }

        // Build the output array B
        for (int i = len - 1; i >= 0; i--) {
            B[C[A[i]] - 1] = A[i];
            C[A[i]]--;
        }
    }
}
// <END-OF-CODE>

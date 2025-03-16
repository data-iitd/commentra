import java.io.BufferedReader;  // Import BufferedReader for reading input
import java.io.IOException;     // Import IOException for handling I/O errors
import java.io.InputStream;     // Import InputStream for system input
import java.io.OutputStream;    // Import OutputStream for system output
import java.io.PrintWriter;     // Import PrintWriter for writing output
import java.util.Arrays;        // Import Arrays for sorting arrays
import java.util.StringTokenizer; // Import StringTokenizer for tokenizing strings

public class Main {
    // Main method to start the program
    public static void main ( String [ ] args ) {
        // Initialize input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        // Create InputReader and PrintWriter objects
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        // Create Solution object and call its solve method
        Solution sol = new Solution();
        sol.solve(in, out);

        // Close the output stream
        out.close();
    }

    // Private nested class for solving the problem
    private static class Solution {
        // Method to solve the problem
        private void solve ( InputReader in , PrintWriter out ) {
            // Read input: number of elements n and the number of summands k
            int n = in.ni();
            int k = in.ni();

            // Read input array a of size n
            int[] a = new int[n];
            for ( int i = 0 ; i < n ; ++ i ) {
                a[i] = in.ni(); // Read next element of array a
            }

            // Sort the array a in parallel using Arrays.parallelSort()
            Arrays.parallelSort(a);

            // Calculate the answer: sum of first k elements of sorted array a
            int ans = 0;
            for ( int i = 0 ; i < k ; ++ i ) {
                ans += a[i];
            }

            // Write the answer to the output stream
            out.println(ans);
        }
    }

    // Nested static class for reading input
    private static class InputReader {
        // Initialize reader and tokenizer
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        // Constructor to initialize InputReader with input stream
        private InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        // Method to read a string token
        private String n() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        // Method to read an integer
        private int ni() {
            return Integer.parseInt(n());
        }
    }
}

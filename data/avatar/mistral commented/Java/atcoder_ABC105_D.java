
import java.io.OutputStream; // Output stream for writing output
import java.io.IOException; // Exception for I/O operations
import java.io.InputStream; // Input stream for reading input
import java.util.StringTokenizer; // Tokenizer for string manipulation
import java.util.HashMap; // Hashmap for storing intermediate results
import java.io.IOException; // Exception for I/O operations
import java.util.InputMismatchException; // Exception for incorrect input format
import java.io.BufferedReader; // Buffered reader for reading input
import java.io.InputStreamReader; // Input stream reader for reading input

public class Main {
    // Main method to start the program
    public static void main(String[] args) {
        InputStream inputStream = System.in; // Input stream from standard input
        OutputStream outputStream = System.out; // Output stream to standard output
        InputReader in = new InputReader(inputStream); // Initialize InputReader
        PrintWriter out = new PrintWriter(outputStream); // Initialize PrintWriter
        TaskD solver = new TaskD(); // Initialize TaskD solver
        solver.solve(1, in, out); // Solve the problem and print the result
        out.close(); // Close the PrintWriter
    }

    // Static inner class to solve the problem
    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            // Read input
            int n = in.nextInt(); // Number of elements in array a
            int m = in.nextInt(); // Modulus value

            // Initialize data structures
            int[] a = in.nextIntArray(n); // Read array a
            HashMap<Integer, Integer> dp = new HashMap<>(); // Hashmap to store intermediate results

            // Initialize variables
            long ans = 0; // Answer variable
            int base = 0; // Base value for hashmap key

            // Process each element in array a
            for (int i = 0; i < n; i++) {
                // Update base value
                base = (base - a[i] % m + m) % m;

                // Update hashmap with current base and its count
                dp.merge(base + a[i] % m, 1, Integer::sum);

                // Update answer variable
                ans += dp.getOrDefault(base, 0);
            }

            // Print the answer
            out.println(ans);
        }
    }

    // Static inner class to read input
    static class InputReader {
        private BufferedReader br; // Buffered reader for reading input
        private StringTokenizer st; // String tokenizer for tokenizing input

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream)); // Initialize buffered reader
            st = new StringTokenizer(""); // Initialize empty string tokenizer
        }

        public String nextString() { // Read a string token
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " "); // Tokenize the line
                } catch (IOException e) {
                    throw new InputMismatchException(); // Throw an exception for incorrect input format
                }
            }
            return st.nextToken(); // Return the next token
        }

        public int nextInt() { // Read an integer token
            return Integer.parseInt(nextString()); // Parse the string token to an integer
        }

        public int[] nextIntArray(int n) { // Read an array of integers
            int[] res = new int[n]; // Initialize the result array
            for (int i = 0; i < n; i++) {
                res[i] = nextInt(); // Read each integer and store it in the result array
            }
            return res; // Return the result array
        }
    }
}


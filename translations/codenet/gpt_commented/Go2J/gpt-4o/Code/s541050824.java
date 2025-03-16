import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    // Buffered reader for input
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    // Print writer for output
    private static PrintWriter writer = new PrintWriter(System.out);
    // String tokenizer for parsing input
    private static StringTokenizer tokenizer;

    // Method to read the next token as a string
    private static String next() throws IOException {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    // Method to read the next token as an integer
    private static long nextInt() throws IOException {
        return Long.parseLong(next());
    }

    // Method to compute the maximum of two long values
    private static long max(long x, long y) {
        return (x > y) ? x : y;
    }

    // Method to compute the ceiling division of x by y
    private static long divUp(long x, long y) {
        return (x + y - 1) / y;
    }

    // Main method where the program execution starts
    public static void main(String[] args) throws IOException {
        solve(); // Call the solve function to execute the main logic
        writer.flush(); // Flush the writer to output
    }

    // Solve method contains the main logic for processing input and producing output
    private static void solve() throws IOException {
        int N = (int) nextInt(); // Read the number of pairs
        long[] T = new long[N]; // Initialize array for T
        long[] A = new long[N]; // Initialize array for A

        // Read pairs of integers into T and A
        for (int i = 0; i < N; i++) {
            T[i] = nextInt();
            A[i] = nextInt();
        }

        long t = T[0], a = A[0]; // Initialize t and a with the first pair
        // Iterate through the remaining pairs to compute the required values
        for (int i = 1; i < N; i++) {
            long r = max(divUp(t, T[i]), divUp(a, A[i])); // Calculate the required multiplier
            t = T[i] * r; // Update t based on the multiplier
            a = A[i] * r; // Update a based on the multiplier
        }
        writer.println(t + a); // Output the final result
    }
}
// <END-OF-CODE>

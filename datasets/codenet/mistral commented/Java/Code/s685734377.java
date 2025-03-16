import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * This class contains the main logic for solving the problem.
 */
public class Main {
    public static void main(String[] args) {
        // Initialize input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        // Create FastScanner and PrintWriter objects
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        // Create an instance of the TaskB class and call its solve method
        TaskB solver = new TaskB();
        solver.solve(1, in, out);

        // Close the PrintWriter
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            // Read the number of test cases and the size of the grid
            int n = in.nextInt();

            // Initialize a 2D char array to represent the grid
            char[][] a = new char[n][n];

            // Initialize constants for hashing
            long P = 37, Q = 47;

            // Initialize arrays for storing powers of P and Q
            long[] powP = new long[n + 1], powQ = new long[n + 1];

            // Calculate powers of P and Q up to n
            powP[0] = powQ[0] = 1;
            for (int i = 1; i <= n; i++) {
                powP[i] = powP[i - 1] * P;
                powQ[i] = powQ[i - 1] * Q;
            }

            // Read the grid from input
            for (int i = 0; i < n; i++) {
                a[i] = in.next().toCharArray();
            }

            // Initialize 2D arrays for storing hash values of rows and columns
            long[][] hashRow = new long[n][n];
            long[][] hashCol = new long[n][n];

            // Calculate hash values for each cell in the grid
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Calculate hash values for the current cell and all other cells
                    for (int k = 0; k < n; k++) {
                        hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                        hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
                    }
                }
            }

            // Initialize a counter for the number of valid subarrays
            int ans = 0;

            // Check each subarray for validity and increment the counter if valid
            for (int A = 0; A < n; A++) {
                for (int B = 0; B < n; B++) {
                    boolean ok = true;
                    // Check each cell in the subarray for validity
                    for (int i = 0; i < n; i++) {
                        ok &= hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A];
                    }
                    // Increment the counter if the subarray is valid
                    ans += ok ? 1 : 0;
                }
            }

            // Print the result
            out.println(ans);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
            }
            return st != null ? st.nextToken() : line;
        }

    }
}

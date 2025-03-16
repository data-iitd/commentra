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
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        // Set up input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        
        // Create an instance of TaskB to solve the problem
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        
        // Close the output stream
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            // Read the size of the matrix
            int n = in.nextInt();
            char[][] a = new char[n][n];
            
            // Initialize hash parameters
            long P = 37, Q = 47;
            long[] powP = new long[n + 1], powQ = new long[n + 1];
            powP[0] = powQ[0] = 1;
            
            // Precompute powers of P and Q
            for (int i = 1; i <= n; i++) {
                powP[i] = powP[i - 1] * P;
                powQ[i] = powQ[i - 1] * Q;
            }
            
            // Read the matrix input
            for (int i = 0; i < n; i++) {
                a[i] = in.next().toCharArray();
            }

            // Initialize hash tables for rows and columns
            long[][] hashRow = new long[n][n];
            long[][] hashCol = new long[n][n];
            
            // Compute hash values for each row and column
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                        hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
                    }
                }
            }

            // Initialize answer counter
            int ans = 0;
            
            // Check for matching hashes between rows and columns
            for (int A = 0; A < n; A++) {
                for (int B = 0; B < n; B++) {
                    boolean ok = true;
                    for (int i = 0; i < n; i++) {
                        // Verify if the hashes match for the current offsets A and B
                        ok &= hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A];
                    }
                    // Increment answer if hashes match
                    ans += ok ? 1 : 0;
                }
            }
            // Output the final count of matches
            out.println(ans);
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        // Constructor to initialize the scanner with input stream
        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        // Method to read the next integer from input
        public int nextInt() {
            return Integer.parseInt(next());
        }

        // Method to read the next token from input
        public String next() {
            // Read a new line if the current token is exhausted
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }
    }
}

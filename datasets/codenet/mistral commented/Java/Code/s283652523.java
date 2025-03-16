import java.io.*;
import java.util.*;
import java.math.BigDecimal;

@SuppressWarnings("unused")
public class Main {
    FastScanner in;
    PrintWriter out;
    final static int MOD = (int)1e9+7;

    // Initialize FastScanner and PrintWriter objects
    void solve(){
        // Read the number of test cases and initialize an integer array A of size N
        int N = in.nextInt();
        int[] A = in.nextIntArray(N);

        // Initialize variables ans and sum
        long ans = 0, sum = A[N-1];

        // Iterate through the array A from the last index to the first index
        for(int i = N - 2; i >= 0; i--){
            // Calculate the contribution of the current element A[i] to the answer ans
            ans += (sum * A[i]) % MOD;
            // Update the sum variable for the next iteration
            sum += A[i];
            sum %= MOD;
        }

        // Print the final answer
        out.println(ans);
    }

    // Main method to call the solve method
    public static void main(String[] args) {
        new Main().m();
    }

    // Initialize FastScanner and PrintWriter objects and call the solve method
    private void m() {
        // Initialize FastScanner and PrintWriter objects
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        /*
        try {
            String path = "input.txt";
            out = new PrintWriter(new BufferedWriter(new FileWriter(new File(path))));
        }catch (IOException e){
            e.printStackTrace();
        }
        */

        // Call the solve method to solve the problem
        solve();

        // Close the input and output streams
        out.flush();
        in.close();
        out.close();
    }

    // FastScanner class to read input efficiently
    static class FastScanner {
        // Initialize the input stream
        private Reader input;

        // Constructor to initialize FastScanner with System.in as default input stream
        public FastScanner() {this(System.in);}

        // Constructor to initialize FastScanner with a custom input stream
        public FastScanner(InputStream stream) {this.input = new BufferedReader(new InputStreamReader(stream));}

        // Close the input stream
        public void close() {
            try {
                this.input.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        // Read an integer from the input stream
        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        // Read a long integer from the input stream
        public long nextLong() {
            try {
                int sign = 1;
                int b = input.read();
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                long ret = b - '0';
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) return sign * ret;
                    ret *= 10;
                    ret += b - '0';
                }
            } catch (IOException e) {
                e.printStackTrace();
                return -1;
            }
        }

        // Read a double from the input stream
        public double nextDouble() {
            try {
                double sign = 1;
                int b = input.read();
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                double ret = b - '0';
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) break;
                    ret *= 10;
                    ret += b - '0';
                }
                if (b != '.') return sign * ret;
                double div = 1;
                b = input.read();
                while ('0' <= b && b <= '9') {
                    ret *= 10;
                    ret += b - '0';
                    div *= 10;
                    b = input.read();
                }
                return sign * ret / div;
            } catch (IOException e) {
                e.printStackTrace();
                return Double.NaN;
            }
        }

        // Read a character from the input stream
        public char nextChar() {
            try {
                int b = input.read();
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                return (char) b;
            } catch (IOException e) {
                e.printStackTrace();
                return 0;
            }
        }

        // Read a string from the input stream
        public String nextStr() {
            try {
                StringBuilder sb = new StringBuilder();
                int b = input.read();
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                while (b != -1 && !Character.isWhitespace(b)) {
                    sb.append((char) b);
                    b = input.read();
                }
                return sb.toString();
            } catch (IOException e) {
                e.printStackTrace();
                return "";
            }
        }

        // Read a line from the input stream
        public String nextLine() {
            try {
                StringBuilder sb = new StringBuilder();
                int b = input.read();
                while (b != -1) {
                    sb.append((char) b);
                    b = input.read();
                }
                return sb.toString();
            } catch (IOException e) {
                e.printStackTrace();
                return "";
            }
        }

        // Read an integer array of size N from the input stream
        public int[] nextIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        // Read an integer array of size N with 1-based indexing from the input stream
        public int[] nextIntArray1Index(int n) {
            int[] res = new int[n + 1];
            for (int i = 0; i < n; i++) {
                res[i + 1] = nextInt();
            }
            return res;
        }

        // Read a long integer array of size N from the input stream
        public long[] nextLongArray(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong();
            }
            return res;
        }

        // Read a long integer array of size N with 1-based indexing from the input stream
        public long[] nextLongArray1Index(int n) {
            long[] res = new long[n + 1];
            for (int i = 0; i < n; i++) {
                res[i + 1] = nextLong();
            }
            return res;
        }

        // Read a double array of size N from the input stream
        public double[] nextDoubleArray(int n) {
            double[] res = new double[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextDouble();
            }
            return res;
        }
    }
}

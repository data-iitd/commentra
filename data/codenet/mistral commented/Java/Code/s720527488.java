
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.PriorityQueue;
import java.math.BigInteger;

public class Main {

    static final InputStream in; // System input stream
    static final PrintWriter out; // System output stream
    static final int INF; // Large integer constant
    static final long LINF; // Large long integer constant

    static {
        in = System.in;
        out = new PrintWriter(System.out);
        INF = Integer.MAX_VALUE / 2;
        LINF = Long.MAX_VALUE / 2;
    }

    public static void main(String[] args) throws IOException {
        InputReader ir = new InputReader(in); // Initialize InputReader
        int m = ir.nextInt(); // Read the number of manjus
        int n = ir.nextInt(); // Read the number of boxes

        // Initialize arrays for box lengths and costs
        int[] manju = new int[m];
        int[] boxlen = new int[n];
        int[] boxcost = new int[n];

        // Read box lengths and costs
        for (int i = 0; i < n; i++) {
            boxlen[i] = ir.nextInt();
            boxcost[i] = ir.nextInt();
            // Print current box details for debugging
            System.out.printf("Box %d: length = %d, cost = %d\n", i + 1, boxlen[i], boxcost[i]);
        }

        // Sort manjus in descending order
        sort(manju);

        // Initialize 2D dp array
        int[][] dp = new int[m + 1][n + 1];

        // Iterate through manjus and boxes in reverse order
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int len = i + boxlen[j] >= m ? m : i + boxlen[j]; // Calculate the length of the manju that can be covered by the current box
                int cnt = 0; // Initialize the number of manjus that can be covered by the current box

                // Iterate through manjus from the start to the end of the current box
                for (int k = i; k < len; k++) {
                    cnt += manju[m - 1 - k];
                }

                // Update dp[i][j] with the maximum value between the current box and the next box
                dp[i][j] = Math.max(dp[i][j], dp[len][j + 1] + cnt - boxcost[j]);
                dp[i][j] = Math.max(dp[i][j], dp[i][j + 1]);
            }
        }

        // Print the result
        out.println(dp[0][0]);
        out.flush();
    }

    // Sort an array in descending order
    public static void sort(int[] a) {
        for (int i = a.length - 1; i >= 1; i--) {
            int t = (int) (Math.random() * i); // Randomly select an index to swap with
            int temp = a[i];
            a[i] = a[t];
            a[t] = temp;
        }

        Arrays.sort(a); // Sort the array in ascending order and then reverse it to get the descending order
    }

    // Custom InputReader class
    static class InputReader {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int curbuf;
        private int lenbuf;

        public InputReader(InputStream in) {
            this.in = in;
        }

        // Read a byte from the input stream
        public int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (curbuf >= lenbuf) {
                curbuf = 0;
                try {
                    lenbuf = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0)
                    return -1;
            }
            return buffer[curbuf++];
        }

        // Check if the current character is a space character
        public boolean isSpaceChar(int c) {
            return c <= 32;
        }

        // Skip whitespaces
        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) {
            }
            return b;
        }

        // Read a string
        public String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!isSpaceChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        // Read an integer
        public int nextInt() {
            int c = skip();
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = readByte();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res = res * 10 + c - '0';
                c = readByte();
            } while (!isSpaceChar(c));
            return (minus) ? -res : res;
        }

        // Read a long integer
        public long nextLong() {
            int c = skip();
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = readByte();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res = res * 10 + c - '0';
                c = readByte();
            } while (!isSpaceChar(c));
            return (minus) ? -res : res;
        }

        // Read an integer array
        public int[] toIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }
    }
}
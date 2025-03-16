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

    // Constants for input and output
    static final InputStream in = System.in;
    static final PrintWriter out = new PrintWriter(System.out);
    static final int INF = Integer.MAX_VALUE / 2; // A large value for initialization
    static final long LINF = Long.MAX_VALUE / 2; // A large long value for initialization

    public static void main(String[] args) throws IOException {
        // Create an InputReader instance to read input
        InputReader ir = new InputReader(in);
        
        // Read the number of items (m) and the number of boxes (n)
        int m = ir.nextInt();
        int n = ir.nextInt();
        
        // Read the values of the items into an array
        int[] manju = ir.toIntArray(m);
        
        // Arrays to hold the lengths and costs of the boxes
        int[] boxlen = new int[n];
        int[] boxcost = new int[n];
        
        // Read the lengths and costs of each box
        for (int i = 0; i < n; i++) {
            boxlen[i] = ir.nextInt();
            boxcost[i] = ir.nextInt();
        }
        
        // Sort the items in descending order
        sort(manju);
        
        // Initialize a DP table to store maximum values
        int[][] dp = new int[m + 1][n + 1];
        
        // Fill the DP table in a bottom-up manner
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Calculate the length of items that can fit in the current box
                int len = i + boxlen[j] >= m ? m : i + boxlen[j];
                int cnt = 0;
                
                // Calculate the total value of items that can fit in the box
                for (int k = i; k < len; k++) cnt += manju[m - 1 - k];
                
                // Update the DP table with the maximum value considering the current box
                dp[i][j] = Math.max(dp[i][j], dp[len][j + 1] + cnt - boxcost[j]);
                
                // Also consider the case where the current box is not used
                dp[i][j] = Math.max(dp[i][j], dp[i][j + 1]);
            }
        }
        
        // Output the maximum value that can be obtained
        out.println(dp[0][0]);
        out.flush(); // Ensure all output is written
    }

    // Method to sort the array using a custom sorting algorithm
    public static void sort(int[] a) {
        // Shuffle the array randomly
        for (int i = a.length - 1; i >= 1; i--) {
            int t = (int) Math.random() * i; // Random index
            int temp = a[i]; 
            a[i] = a[t]; 
            a[t] = temp; // Swap elements
        }
        // Sort the array in ascending order
        Arrays.sort(a);
    }

    // InputReader class to handle input operations
    static class InputReader {
        private InputStream in;
        private byte[] buffer = new byte[1024]; // Buffer for reading input
        private int curbuf; // Current buffer position
        private int lenbuf; // Length of the buffer

        // Constructor to initialize InputReader with InputStream
        public InputReader(InputStream in) {
            this.in = in;
        }

        // Method to read a byte from the input stream
        public int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (curbuf >= lenbuf) {
                curbuf = 0;
                try {
                    lenbuf = in.read(buffer); // Read into buffer
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1; // End of stream
            }
            return buffer[curbuf++]; // Return the current byte
        }

        // Method to check if a character is a space character
        public boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        // Method to skip space characters
        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b));
            return b;
        }

        // Method to read the next string from input
        public String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!isSpaceChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        // Method to read the next integer from input
        public int nextInt() {
            int c = readByte();
            while (isSpaceChar(c)) c = readByte();
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
            return (minus) ? -res : res; // Return the integer value
        }

        // Method to read the next long integer from input
        public long nextLong() {
            int c = readByte();
            while (isSpaceChar(c)) c = readByte();
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
            return (minus) ? -res : res; // Return the long integer value
        }

        // Method to read an array of integers from input
        public int[] toIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt(); // Fill the array
            return a; // Return the array
        }
    }
}

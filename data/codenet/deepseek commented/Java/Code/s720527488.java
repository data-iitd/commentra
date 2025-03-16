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

// Main class to solve the problem
public class Main {

// Define constants for maximum values
static final InputStream in = System.in;
static final PrintWriter out = new PrintWriter(System.out);
static final int INF = Integer.MAX_VALUE / 2;
static final long LINF = Long.MAX_VALUE / 2;

// Main method to execute the program
public static void main(String[] args) throws IOException {
    // Initialize InputReader to read input from standard input
    InputReader ir = new InputReader(in);
    int m = ir.nextInt(); // Read number of manju
    int n = ir.nextInt(); // Read number of box options
    int[] manju = ir.toIntArray(m); // Read manju array
    int[] boxlen = new int[n]; // Array to store box lengths
    int[] boxcost = new int[n]; // Array to store box costs
    for (int i = 0; i < n; i++) {
        boxlen[i] = ir.nextInt(); // Read box lengths
        boxcost[i] = ir.nextInt(); // Read box costs
    }
    // Sort the manju array
    sort(manju);
    // Initialize a 2D array to store the maximum profit
    int[][] dp = new int[m + 1][n + 1];
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int len = i + boxlen[j] >= m ? m : i + boxlen[j]; // Calculate the end length
            int cnt = 0;
            for (int k = i; k < len; k++) cnt += manju[m - 1 - k]; // Calculate the total value of manju in the box
            dp[i][j] = Math.max(dp[i][j], dp[len][j + 1] + cnt - boxcost[j]); // Update dp with the new profit
            dp[i][j] = Math.max(dp[i][j], dp[i][j + 1]); // Consider not using the current box
        }
    }
    // Print the maximum profit
    out.println(dp[0][0]);
    out.flush(); // Ensure the output is printed
}

// Custom sort method to sort the manju array
public static void sort(int[] a) {
    for (int i = a.length - 1; i >= 1; i--) {
        int t = (int) (Math.random() * i); // Randomly select an index
        int temp = a[i]; a[i] = a[t]; a[t] = temp; // Swap elements
    }
    Arrays.sort(a); // Sort the array
}

// Inner class to read input from the InputStream
static class InputReader {
    private InputStream in;
    private byte[] buffer = new byte[1024];
    private int curbuf;
    private int lenbuf;

    public InputReader(InputStream in) {
        this.in = in;
    }

    // Read a byte from the InputStream
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

    // Check if a character is a space character
    public boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    // Skip characters until a non-space character is found
    private int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b));
        return b;
    }

    // Read a string from the InputStream
    public String next() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!isSpaceChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    // Read an integer from the InputStream
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
        return (minus) ? -res : res;
    }

    // Read a long integer from the InputStream
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
        return (minus) ? -res : res;
    }

    // Convert a string of integers to an array of integers
    public int[] toIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }
}
}

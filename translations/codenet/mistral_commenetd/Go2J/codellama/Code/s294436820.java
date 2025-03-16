
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    // Constants for large prime numbers used in modular arithmetic.
    static final int INF = 1000000007;
    static final int INF2 = 1000000009;
    static final int INF3 = 998244353;

    // Global variable for debug mode.
    static boolean DEBUG = false;

    // -----------------------------------------------------------------------------
    // IO helper functions

    // Returns next token from input. It must be initialized by SetInput() before the first call.
    static StringTokenizer st = new StringTokenizer("");
    static String nextToken() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    // Returns next token from input. It must be initialized by SetInput() before the first call.
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String nextLine() throws IOException {
        return br.readLine();
    }

    // Set IO functions for interactive input/output.
    static void SetInteractive(PrintWriter out, BufferedReader in) {
        br = in;
        pw = out;
    }

    // Setup OutputBuffer and OutputWriter.
    static PrintWriter pw = new PrintWriter(System.out);
    static void SetOutput(PrintWriter out) {
        pw = out;
    }

    // Flushes OutputBuffer
    static void Flush() {
        pw.flush();
    }

    // Returns true if c is a white space
    static boolean IsSpace(char c) {
        switch (c) {
            case '\t', '\n', '\v', '\f', '\r', ' ':
                return true;
        }
        return false;
    }

    // Returns true if c is a new line
    static boolean IsNewLine(char c) {
        switch (c) {
            case '\n', '\r':
                return true;
        }
        return false;
    }

    // Setup nextToken with input buffer.
    static void SetInput(BufferedReader r) {
        br = r;
    }

    // Setup nextToken without input buffer.
    static void SetUnbufferedInput(BufferedReader r) {
        br = r;
    }

    // -----------------------------------------------------------------------------
    // IO functions

    // Reads next token and return it as []byte
    static byte[] readb() throws IOException {
        String s = nextToken();
        return s.getBytes();
    }

    // Reads next token and return it as string
    static String reads() throws IOException {
        return nextToken();
    }

    // Read next line as []byte. Trailing '\n' will not be included.
    // See also comments on readb()
    static byte[] readbln() throws IOException {
        String s = nextLine();
        return s.getBytes();
    }

    // Read next line as string
    static String readsln() throws IOException {
        return nextLine();
    }

    // Reads next token and return it as int64
    static long readll() throws IOException {
        return Long.parseLong(nextToken());
    }

    // Reads next token and return it as int
    static int readi() throws IOException {
        return Integer.parseInt(nextToken());
    }

    // Reads next token and return it as float64
    static double readf() throws IOException {
        return Double.parseDouble(nextToken());
    }

    // Write args to OutputWriter with the format f
    static void printf(String f, Object... args) {
        pw.printf(f, args);
    }

    // Write args to OutputWriter without format
    static void println(Object... args) {
        pw.println(args);
    }

    // Write args to stderr with the format f
    static void eprintf(String f, Object... args) {
        System.err.printf(f, args);
    }

    // Write args to stderr without format
    static void eprintln(Object... args) {
        System.err.println(args);
    }

    static void debugf(String f, Object... args) {
        if (!DEBUG) {
            return;
        }
        System.err.printf(f, args);
    }

    static void debug(Object... args) {
        if (!DEBUG) {
            return;
        }
        System.err.println(args);
    }

    // -----------------------------------------------------------------------------
    // Utilities

    static int sumSlice(int[] a) {
        int res = 0;
        for (int v : a) {
            res += v;
        }
        return res;
    }

    static long sumSlicell(long[] a) {
        long res = 0;
        for (long v : a) {
            res += v;
        }
        return res;
    }

    // -----------------------------------------------------------------------------
    // Simple math functions

    // min returns the minimum of two integers.
    static int min(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    // minll returns the minimum of two int64.
    static long minll(long a, long b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    // minf returns the minimum of two float64.
    static double minf(double a, double b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    // max returns the maximum of two integers.
    static int max(int a, int b) {
        if (a < b) {
            return b;
        }
        return a;
    }

    // maxll returns the maximum of two int64.
    static long maxll(long a, long b) {
        if (a < b) {
            return b;
        }
        return a;
    }

    // maxf returns the maximum of two float64.
    static double maxf(double a, double b) {
        if (a < b) {
            return b;
        }
        return a;
    }

    // abs returns the absolute value of an integer.
    static int abs(int a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    // absll returns the absolute value of an int64.
    static long absll(long a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    // absf returns the absolute value of a float64.
    static double absf(double a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    // egcd returns the greatest common divisor of a and b, along with x and y such that a*x + b*y = gcd.
    static int egcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        int d = egcd(b, a % b);
        return d;
    }

    // gcd returns the greatest common divisor of two integers.
    static int gcd(int a, int b) {
        int d = egcd(a, b);
        return d;
    }

    // -----------------------------------------------------------------------------
    // Main function

    static void init() {
        // for non-interactive
        SetInput(new BufferedReader(new InputStreamReader(System.in)));
        SetOutput(new PrintWriter(System.out));

        // Enable below when interactive. Its ok to leave above intact.
        SetInteractive(new PrintWriter(System.out), new BufferedReader(new InputStreamReader(System.in)));
    }

    static void main() throws IOException {
        // Read input
        int h = readi();
        int w = readi();
        int a = readi();
        int[][] m = new int[h][w];
        for (int i = 0; i < h; i++) {
            String s = readsln();
            for (int j = 0; j < w; j++) {
                m[i][j] = s.charAt(j);
            }
        }

        // Solve the problem
        int answer = solve(h, w, a, m);

        // Print the result
        println(answer);
    }

    // Function to count the number of black cells in a grid.
    static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        debug("new table");
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == Black) {
                    count++;
                }
            }
            debug(m[i]);
        }
        debug("result : ", count);
        return count;
    }

    // Function to solve the problem.
    static int solve(int h, int w, int a, int[][] m) {
        int result = 0;
        for (int i = 0; i < 1 << h; i++) {
            for (int k = 0; k < 1 << w; k++) {
                int[][] tmp = new int[h][w];
                for (int j = 0; j < h; j++) {
                    tmp[j] = m[j].clone();
                }
                for (int j = 0; j < h; j++) {
                    int hPainted = (1 << j & i);
                    if (hPainted > 0) {
                        debug("painted ", j, 1 << j, i, hPainted);
                        for (int l = 0; l < w; l++) {
                            tmp[j][l] = 1;
                        }
                    }
                }
                for (int j = 0; j < w; j++) {
                    int wPainted = (1 << j & k);
                    if (wPainted > 0) {
                        for (int l = 0; l < h; l++) {
                            tmp[l][j] = 1;
                        }
                    }
                }
                debug("i", Integer.toBinaryString(i));
                debug("k", Integer.toBinaryString(k));
                if (countBlack(h, w, tmp) == a) {
                    result++;
                }
            }
        }
        return result;
    }

    // Constants for black cell representation.
    static final int Black = 35;

    
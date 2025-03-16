
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // -----------------------------------------------------------------------------

    // IO helper functions

    // Returns next token from input.  It must be initialized by SetInput()
    // before the first call.
    private static StringTokenizer st;
    private static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    // Returns next token from input.  It must be initialized by SetInput()
    // before the first call.
    private static BufferedReader br;
    private static String nextLine() throws IOException {
        return br.readLine();
    }

    // Set IO functions for interactive input/output.
    private static void SetInteractive(PrintWriter pw, BufferedReader br) {
        Main.pw = pw;
        Main.br = br;
    }

    // Setup OutputBuffer and OutputWriter.
    private static PrintWriter pw;
    private static void SetOutput(PrintWriter pw) {
        Main.pw = pw;
    }

    // Flushes OutputBuffer
    private static void Flush() {
        if (pw != null) {
            pw.flush();
        }
    }

    // Returns true if c is a white space
    private static boolean IsSpace(char c) {
        switch (c) {
            case '\t':
            case '\n':
            case '\v':
            case '\f':
            case '\r':
            case ' ':
                return true;
        }
        return false;
    }

    // Returns true if c is a white space
    private static boolean IsNewLine(char c) {
        switch (c) {
            case '\n':
            case '\r':
                return true;
        }
        return false;
    }

    // Setup nextToken with input buffer.
    private static void SetInput(BufferedReader br) {
        Main.br = br;
    }

    // Setup nextToken without input buffer.
    private static void SetUnbufferedInput(BufferedReader br) {
        Main.br = br;
    }

    // -----------------------------------------------------------------------------

    // IO functions

    // Reads next token and return it as []byte
    private static byte[] readb() throws IOException {
        String s = nextToken();
        return s.getBytes();
    }

    // Reads next token and return it as string
    private static String reads() throws IOException {
        return nextToken();
    }

    // Read next line as []byte.  Trailing '\n' will not be included.
    // See also comments on readb()
    private static byte[] readbln() throws IOException {
        String s = nextLine();
        return s.getBytes();
    }

    // Read next line as string
    private static String readsln() throws IOException {
        return nextLine();
    }

    // Reads next token and return it as int64
    private static long readll() throws IOException {
        return Long.parseLong(nextToken());
    }

    // Reads next token and return it as int
    private static int readi() throws IOException {
        return Integer.parseInt(nextToken());
    }

    // Reads next token and return it as float64
    private static double readf() throws IOException {
        return Double.parseDouble(nextToken());
    }

    // Write args to OutputWriter with the format f
    private static void printf(String f, Object... args) {
        pw.printf(f, args);
    }

    // Write args to OutputWriter without format
    private static void println(Object... args) {
        pw.println(args);
    }

    // Write args to stderr with the format f
    private static void eprintf(String f, Object... args) {
        System.err.printf(f, args);
    }

    // Write args to stderr without format
    private static void eprintln(Object... args) {
        System.err.println(args);
    }

    private static void debugf(String f, Object... args) {
        if (!DEBUG) {
            return;
        }
        System.err.printf(f, args);
    }

    private static void debug(Object... args) {
        if (!DEBUG) {
            return;
        }
        System.err.println(args);
    }

    // -----------------------------------------------------------------------------

    // Utilities

    private static int sumSlice(int[] a) {
        int res = 0;
        for (int v : a) {
            res += v;
        }
        return res;
    }

    private static long sumSlicell(long[] a) {
        long res = 0;
        for (long v : a) {
            res += v;
        }
        return res;
    }

    private static int[] readInts(int N) throws IOException {
        if (N == 0) {
            N = readi();
        }
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = readi();
        }
        return a;
    }

    private static long[] readIntsll(int N) throws IOException {
        if (N == 0) {
            N = readi();
        }
        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = readll();
        }
        return a;
    }

    // -----------------------------------------------------------------------------

    // Simple math functions

    private static final int INF = 1000000007;
    private static final int INF2 = 1000000009;
    private static final int INF3 = 998244353;

    private static int min(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    private static long minll(long a, long b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    private static double minf(double a, double b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    private static int max(int a, int b) {
        if (a < b) {
            return b;
        }
        return a;
    }

    private static long maxll(long a, long b) {
        if (a < b) {
            return b;
        }
        return a;
    }

    private static double maxf(double a, double b) {
        if (a < b) {
            return b;
        }
        return a;
    }

    private static int abs(int a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    private static long absll(long a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    private static double absf(double a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    // egcd(a, b) returns d, x, y:
    //   d is gcd(a,b)
    //   x, y are  integers that satisfy ax + by = d
    private static int[] egcd(int a, int b) {
        if (b == 0) {
            return new int[] { a, 1, 0 };
        }
        int[] dxy = egcd(b, a % b);
        int d = dxy[0];
        int x = dxy[1];
        int y = dxy[2];
        return new int[] { d, y, x - a / b * y };
    }

    private static long[] egcdll(long a, long b) {
        if (b == 0) {
            return new long[] { a, 1, 0 };
        }
        long[] dxy = egcdll(b, a % b);
        long d = dxy[0];
        long x = dxy[1];
        long y = dxy[2];
        return new long[] { d, y, x - a / b * y };
    }

    private static int gcd(int a, int b) {
        int d = egcd(a, b)[0];
        return d;
    }

    private static long gcdll(long a, long b) {
        long d = egcdll(a, b)[0];
        return d;
    }

    // set up IO functions
    public static void main(String[] args) throws IOException {
        // for non-interactive
        SetInput(new BufferedReader(new InputStreamReader(System.in)));
        SetOutput(new PrintWriter(System.out));

        // Enable below when interactive.  Its ok to leave above intact.
        // SetInteractive(new PrintWriter(System.out), new BufferedReader(new InputStreamReader(System.in)));

        int h, w, k;
        h = readi();
        w = readi();
        k = readi();
        int[][] m = new int[h][w];
        for (int i = 0; i < h; i++) {
            String s = reads();
            for (int j = 0; j < w; j++) {
                m[i][j] = s.charAt(j);
            }
        }

        int answer = solve(h, w, k, m);
        println(answer);
    }

    private static int solve(int h, int w, int a, int[][] m) {
        int result = 0;
        for (int i = 0; i < 1 << h; i++) {
            for (int k = 0; k < 1 << w; k++) {
                int[][] tmp = new int[h][w];
                for (int j = 0; j < h; j++) {
                    tmp[j] = Arrays.copyOf(m[j], w);
                }
                for (int j = 0; j < h; j++) {
                    int hPainted = (1 << j & i);
                    if (hPainted > 0) {
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
                if (countBlack(h, w, tmp) == a) {
                    result++;
                }
            }
        }
        return result;
    }

    private static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        debug("new table");
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == 35) {
                    count++;
                }
            }
            debug(Arrays.toString(m[i]));
        }
        debug("result : ", count);
        return count;
    }

    // 


// Package main defines the entry point of the program.
package main;

// Importing necessary libraries for the program.
import java.io.*;
import java.util.*;

// Constants used in the program.
public class s069675863{
    public static final int MOD = 1000000000 + 7;
    public static final int ALPHABET_NUM = 26;
    public static final int INF_INT64 = Integer.MAX_VALUE;
    public static final int INF_BIT60 = 1L << 60;
    public static final int INF_INT32 = Integer.MAX_VALUE;
    public static final int INF_BIT30 = 1 << 30;
    public static final int NIL = -1;
    public static final int WHITE = 0;
    public static final int GRAY = 1;
    public static final int BLACK = 2;

    // init function initializes the input reader and output writer.
    public static void init() {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    // s069675863 function reads input, processes the data, and prints the result.
    public static void main(String[] args) {
        init();
        char[] S = next().toCharArray();
        int x = nextInt(), y = nextInt();

        boolean[][] dpx = new boolean[10001][20001];
        boolean[][] dpy = new boolean[10001][20001];
        dpx[0][10000] = true;
        dpy[0][10000] = true;

        int[] F = new int[10001];
        int cur = 0;
        for (int i = 0; i < S.length; i++) {
            if (S[i] == 'F') {
                cur++;
            } else {
                F[i] = cur;
                cur = 0;
            }
        }
        F[S.length] = cur;

        int[] evens = new int[10001];
        int[] odds = new int[10001];
        int evensIdx = 0, oddsIdx = 0;
        for (int i = 0; i <= S.length; i++) {
            if (i % 2 == 0) {
                evens[evensIdx++] = F[i];
            } else {
                odds[oddsIdx++] = F[i];
            }
        }

        for (int i = 0; i < evensIdx; i++) {
            int val = evens[i];
            for (int j = 20000; j >= 0; j--) {
                if (j + val <= 20000) {
                    dpx[i + 1][j + val] |= dpx[i][j];
                }
                if (j - val >= 0) {
                    dpx[i + 1][j - val] |= dpx[i][j];
                }
            }
        }
        for (int i = 0; i < oddsIdx; i++) {
            int val = odds[i];
            for (int j = 20000; j >= 0; j--) {
                if (j + val <= 20000) {
                    dpy[i + 1][j + val] |= dpy[i][j];
                }
                if (j - val >= 0) {
                    dpy[i + 1][j - val] |= dpy[i][j];
                }
            }
        }

        if (dpx[evensIdx][x + 10000] && dpy[oddsIdx][y + 10000]) {
            out.println("Yes");
        } else {
            out.println("No");
        }

        out.flush();
    }

    // ReadString returns a WORD string.
    public static String ReadString() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    // ReadInt returns an integer.
    public static int ReadInt() {
        return Integer.parseInt(ReadString());
    }

    // ReadInt2 returns two integers.
    public static int[] ReadInt2() {
        String[] s = ReadString().split(" ");
        int[] A = new int[2];
        A[0] = Integer.parseInt(s[0]);
        A[1] = Integer.parseInt(s[1]);
        return A;
    }

    // ReadInt3 returns three integers.
    public static int[] ReadInt3() {
        String[] s = ReadString().split(" ");
        int[] A = new int[3];
        A[0] = Integer.parseInt(s[0]);
        A[1] = Integer.parseInt(s[1]);
        A[2] = Integer.parseInt(s[2]);
        return A;
    }

    // ReadInt4 returns four integers.
    public static int[] ReadInt4() {
        String[] s = ReadString().split(" ");
        int[] A = new int[4];
        A[0] = Integer.parseInt(s[0]);
        A[1] = Integer.parseInt(s[1]);
        A[2] = Integer.parseInt(s[2]);
        A[3] = Integer.parseInt(s[3]);
        return A;
    }

    // ReadInt64 returns an integer.
    public static long ReadInt64() {
        return Long.parseLong(ReadString());
    }

    // ReadInt64_2 returns two integers.
    public static long[] ReadInt64_2() {
        String[] s = ReadString().split(" ");
        long[] A = new long[2];
        A[0] = Long.parseLong(s[0]);
        A[1] = Long.parseLong(s[1]);
        return A;
    }

    // ReadInt64_3 returns three integers.
    public static long[] ReadInt64_3() {
        String[] s = ReadString().split(" ");
        long[] A = new long[3];
        A[0] = Long.parseLong(s[0]);
        A[1] = Long.parseLong(s[1]);
        A[2] = Long.parseLong(s[2]);
        return A;
    }

    // ReadInt64_4 returns four integers.
    public static long[] ReadInt64_4() {
        String[] s = ReadString().split(" ");
        long[] A = new long[4];
        A[0] = Long.parseLong(s[0]);
        A[1] = Long.parseLong(s[1]);
        A[2] = Long.parseLong(s[2]);
        A[3] = Long.parseLong(s[3]);
        return A;
    }

    // ReadInt64Slice returns an integer slice.
    public static long[] ReadInt64Slice(int n) {
        long[] A = new long[n];
        for (int i = 0; i < n; i++) {
            A[i] = Long.parseLong(ReadString());
        }
        return A;
    }

    // ReadFloat64 returns a float.
    public static double ReadFloat64() {
        return Double.parseDouble(ReadString());
    }

    // ReadFloat64Slice returns a float slice.
    public static double[] ReadFloat64Slice(int n) {
        double[] A = new double[n];
        for (int i = 0; i < n; i++) {
            A[i] = Double.parseDouble(ReadString());
        }
        return A;
    }

    // ReadruneSlice returns a rune slice.
    public static char[] ReadruneSlice() {
        return ReadString().toCharArray();
    }

    // ZeroPaddingRuneSlice returns a rune slice with leading zeros.
    public static char[] ZeroPaddingRuneSlice(int n, int digitsNum) {
        String sn = Integer.toBinaryString(n);

        int residualLength = digitsNum - sn.length();
        if (residualLength <= 0) {
            return sn.toCharArray();
        }

        char[] zeros = new char[residualLength];
        Arrays.fill(zeros, '0');

        char[] res = new char[residualLength + sn.length()];
        int idx = 0;
        for (int i = 0; i < zeros.length; i++) {
            res[idx++] = zeros[i];
        }
        for (int i = 0; i < sn.length(); i++) {
            res[idx++] = sn.charAt(i);
        }

        return res;
    }

    // Strtoi converts a string to an integer.
    public static int Strtoi(String s) {
        try {
            return Integer.parseInt(s);
        } catch (NumberFormatException e) {
            throw new RuntimeException(e);
        }
    }

    // PrintIntsLine prints an integer slice in one line.
    public static String PrintIntsLine(int... A) {
        return Arrays.toString(A).replace(",", "");
    }

    // PrintInts64Line prints an integer slice in one line.
    public static String PrintInts64Line(long... A) {
        return Arrays.toString(A).replace(",", "");
    }

    // PrintfDebug prints a debug message.
    public static void PrintfDebug(String format, Object... args) {
        System.err.printf(format, args);
    }

    // PrintfBufStdout prints a message to stdout.
    public static void PrintfBufStdout(String format, Object... args) {
        out.printf(format, args);
    }

    // NextInt returns the next integer from stdin.
    private static int nextInt() {
        return Integer.parseInt(next());
    }

    // Next returns the next string from stdin.
    private static String next() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    // Variables
    private static BufferedReader in;
    private static PrintWriter out;
}

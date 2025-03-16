import java.io.*;
import java.util.*;

public class Main {
    static boolean DEBUG = false;

    // IO helper functions
    static BufferedReader reader;
    static PrintWriter writer;
    static StringTokenizer tokenizer;

    static void setInteractive(PrintWriter writer, BufferedReader reader) {
        Main.reader = reader;
        Main.writer = writer;
        tokenizer = null;
    }

    static void setOutput(PrintWriter writer) {
        Main.writer = writer;
    }

    static void flush() {
        writer.flush();
    }

    static boolean isSpace(char c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\f' || c == '\v';
    }

    static boolean isNewLine(char c) {
        return c == '\n' || c == '\r';
    }

    static void setInput(BufferedReader reader) {
        Main.reader = reader;
        tokenizer = null;
    }

    static void setUnbufferedInput(BufferedReader reader) {
        Main.reader = reader;
        tokenizer = null;
    }

    static String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static String nextLine() throws IOException {
        return reader.readLine();
    }

    static int readInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static long readLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static void printf(String format, Object... args) {
        writer.printf(format, args);
    }

    static void println(Object... args) {
        writer.println(args);
    }

    static void eprintf(String format, Object... args) {
        if (DEBUG) {
            writer.printf(format, args);
        }
    }

    static void eprintln(Object... args) {
        if (DEBUG) {
            writer.println(args);
        }
    }

    static int sumSlice(int[] a) {
        int res = 0;
        for (int v : a) {
            res += v;
        }
        return res;
    }

    static long sumSlice(long[] a) {
        long res = 0;
        for (long v : a) {
            res += v;
        }
        return res;
    }

    static int[] readInts(int N) throws IOException {
        if (N == 0) {
            N = readInt();
        }
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = readInt();
        }
        return a;
    }

    static long[] readLongs(int N) throws IOException {
        if (N == 0) {
            N = readInt();
        }
        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = readLong();
        }
        return a;
    }

    static final int INF = 1000000007;
    static final int INF2 = 1000000009;
    static final int INF3 = 998244353;

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static long min(long a, long b) {
        return a < b ? a : b;
    }

    static double min(double a, double b) {
        return a < b ? a : b;
    }

    static int max(int a, int b) {
        return a < b ? b : a;
    }

    static long max(long a, long b) {
        return a < b ? b : a;
    }

    static double max(double a, double b) {
        return a < b ? b : a;
    }

    static int abs(int a) {
        return a < 0 ? -a : a;
    }

    static long abs(long a) {
        return a < 0 ? -a : a;
    }

    static double abs(double a) {
        return a < 0 ? -a : a;
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static void init() {
        setInput(new BufferedReader(new InputStreamReader(System.in)));
        setOutput(new PrintWriter(System.out));
    }

    public static void main(String[] args) throws IOException {
        init();
        int h = readInt(), w = readInt(), k = readInt();
        int[][] m = new int[h][w];
        for (int i = 0; i < h; i++) {
            String s = nextToken();
            for (int j = 0; j < w; j++) {
                m[i][j] = s.charAt(j);
            }
        }

        int answer = solve(h, w, k, m);
        println(answer);
        flush();
    }

    static final int Black = 35;

    static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == Black) {
                    count++;
                }
            }
        }
        return count;
    }

    static int solve(int h, int w, int a, int[][] m) {
        int result = 0;
        for (int i = 0; i < 1 << h; i++) {
            for (int k = 0; k < 1 << w; k++) {
                int[][] tmp = new int[h][w];
                for (int j = 0; j < h; j++) {
                    System.arraycopy(m[j], 0, tmp[j], 0, w);
                }
                for (int j = 0; j < h; j++) {
                    if ((i & (1 << j)) > 0) {
                        for (int l = 0; l < w; l++) {
                            tmp[j][l] = 1;
                        }
                    }
                }
                for (int j = 0; j < w; j++) {
                    if ((k & (1 << j)) > 0) {
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
}

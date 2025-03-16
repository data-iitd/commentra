
// Package main defines the entry point of the program.
package main

// Importing necessary libraries for the program.
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



// Constants used in the program.
class Constants {
    public static final int MOD = 1000000000 + 7;
    public static final int ALPHABET_NUM = 26;
    public static final int INF_INT64 = (int) (Math.pow(2, 63) - 1);
    public static final int INF_BIT60 = (int) (Math.pow(2, 60) - 1);
    public static final int INF_INT32 = (int) (Math.pow(2, 31) - 1);
    public static final int INF_BIT30 = (int) (Math.pow(2, 30) - 1);
    public static final int NIL = -1;
    public static final int WHITE = 0;
    public static final int GRAY = 1;
    public static final int BLACK = 2;
}



// init function initializes the input reader and output writer.
public static void init() {
    reader = new BufferedReader(new InputStreamReader(System.in));
    writer = new PrintWriter(System.out);
}



// Main function reads input, processes the data, and prints the result.
public static void main(String[] args) {
    init();

    String S = next();
    int x = nextInt();
    int y = nextInt();

    List<Integer> F = new ArrayList<>();
    int cur = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S.charAt(i) == 'F') {
            cur++;
        } else {
            F.add(cur);
            cur = 0;
        }
    }
    F.add(cur);
    // PrintfDebug("%v\n", F);

    List<Integer> evens = new ArrayList<>();
    List<Integer> odds = new ArrayList<>();
    for (int i = 0; i < F.size(); i++) {
        if (i % 2 == 0) {
            evens.add(F.get(i));
        } else {
            odds.add(F.get(i));
        }
    }

    boolean[][] dpx = new boolean[evens.size() + 1][20000];
    boolean[][] dpy = new boolean[odds.size() + 1][20000];
    dpx[0][10000] = true;
    dpy[0][10000] = true;
    for (int i = 0; i < evens.size(); i++) {
        int val = evens.get(i);
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i != 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }
    for (int i = 0; i < odds.size(); i++) {
        int val = odds.get(i);
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
            }
            if (j - val >= 2000) {
                dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
            }
        }
    }

    if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
        writer.println("Yes");
    } else {
        writer.println("No");
    }

    writer.flush();
    writer.close();
}



// ReadString returns a WORD string.
public static String next() {
    while (st == null || !st.hasMoreTokens()) {
        try {
            st = new Scanner(reader.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    return st.nextToken();
}

public static int nextInt() {
    return Integer.parseInt(next());
}

public static long nextLong() {
    return Long.parseLong(next());
}

public static double nextDouble() {
    return Double.parseDouble(next());
}



// ReadInt returns an integer.
public static int readInt() {
    return Integer.parseInt(next());
}
public static int readInt2() {
    return Integer.parseInt(next()) + Integer.parseInt(next());
}
public static int readInt3() {
    return Integer.parseInt(next()) + Integer.parseInt(next()) + Integer.parseInt(next());
}
public static int readInt4() {
    return Integer.parseInt(next()) + Integer.parseInt(next()) + Integer.parseInt(next()) + Integer.parseInt(next());
}

public static long readLong() {
    return Long.parseLong(next());
}
public static long readLong2() {
    return Long.parseLong(next()) + Long.parseLong(next());
}
public static long readLong3() {
    return Long.parseLong(next()) + Long.parseLong(next()) + Long.parseLong(next());
}
public static long readLong4() {
    return Long.parseLong(next()) + Long.parseLong(next()) + Long.parseLong(next()) + Long.parseLong(next());
}

public static double readDouble() {
    return Double.parseDouble(next());
}

public static double readDouble2() {
    return Double.parseDouble(next()) + Double.parseDouble(next());
}

public static double readDouble3() {
    return Double.parseDouble(next()) + Double.parseDouble(next()) + Double.parseDouble(next());
}

public static double readDouble4() {
    return Double.parseDouble(next()) + Double.parseDouble(next()) + Double.parseDouble(next()) + Double.parseDouble(next());
}



// PrintfDebug is wrapper of fmt.Fprintf(os.Stderr, format, a...)
public static void PrintfDebug(String format, Object... a) {
    System.err.printf(format, a);
}



// PrintfBufStdout is function for output strings to buffered os.Stdout.
public static void PrintfBufStdout(String format, Object... a) {
    System.out.printf(format, a);
}



// ReadString returns a WORD string.
public static String nextLine() {
    String str = "";
    try {
        str = reader.readLine();
    } catch (IOException e) {
        e.printStackTrace();
    }
    return str;
}



// ReadRuneSlice returns a rune slice.
public static Rune[] nextRuneSlice() {
    String str = nextLine();
    return str.codePoints().toArray();
}



// ReadString returns a WORD string.
public static String[] nextStringArray(int n) {
    String[] buf = new String[n];
    for (int i = 0; i < n; i++) {
        buf[i] = next();
    }
    return buf;
}



// ReadInt returns an integer.
public static int[] nextIntArray(int n) {
    int[] buf = new int[n];
    for (int i = 0; i < n; i++) {
        buf[i] = nextInt();
    }
    return buf;
}



// ReadInt returns an integer.
public static long[] nextLongArray(int n) {
    long[] buf = new long[n];
    for (int i = 0; i < n; i++) {
        buf[i] = nextLong();
    }
    return buf;
}



// ReadInt returns an integer.
public static double[] nextDoubleArray(int n) {
    double[] buf = new double[n];
    for (int i = 0; i < n; i++) {
        buf[i] = nextDouble();
    }
    return buf;
}



// ReadInt returns an integer.
public static int[][] nextIntArray(int n, int m) {
    int[][] buf = new int[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            buf[i][j] = nextInt();
        }
    }
    return buf;
}



// ReadInt returns an integer.
public static long[][] nextLongArray(int n, int m) {
    long[][] buf = new long[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            buf[i][j] = nextLong();
        }
    }
    return buf;
}



// ReadInt returns an integer.
public static double[][] nextDoubleArray(int n, int m) {
    double[][] buf = new double[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            buf[i][j] = nextDouble();
        }
    }
    return buf;
}



// ReadInt returns an integer.
public static int[][][] nextIntArray(int n, int m, int l) {
    int[][][] buf = new int[n][m][l];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                buf[i][j][k] = nextInt();
            }
        }
    }
    return buf;
}



// ReadInt returns an integer.
public static long[][][] nextLongArray(int n, int m, int l) {
    long[][][] buf = new long[n][m][l];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                buf[i][j][k] = nextLong();
            }
        }
    }
    return buf;
}



// ReadInt returns an integer.
public static double[][][] nextDoubleArray(int n, int m, int l) {
    double[][][] buf = new double[n][m][l];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                buf[i][j][k] = nextDouble();
            }
        }
    }
    return buf;
}



// ReadInt returns an integer.
public static int[][][][] nextIntArray(int n, int m, int l, int r) {
    int[][][][] buf = new int[n][m][l][r];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                for (int p = 0; p < r; p++) {
                    buf[i][j][k][p] = nextInt();
                }
            }
        }
    }
    return buf;
}



// ReadInt returns an integer.
public static long[][][][] nextLongArray(int n, int m, int l, int r) {
    long[][][][] buf = new long[n][m][l][r];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                for (int p = 0; p < r; p++) {
                    buf[i][j][k][p] = nextLong();
                }
            }
        }
    }
    return buf;
}



// ReadInt returns an integer.
public static double[][][][] nextDoubleArray(int n, int m, int l, int r) {
    double[][][][] buf = new double[n][m][l][r];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                for (int p = 0; p < r; p++) {
                    buf[i][j][k][p] = nextDouble();
                }
            }
        }
    }
    return buf;
}



// ReadInt returns an integer.
public static int[][][][][] nextIntArray(int n, int m, int l, int r, int t) {
    int[][][][][] buf = new int[n][m][l][r][t];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                for (int p = 0; p < r; p++) {
                    for (int q = 0; q < t; q++) {
                        buf[i][j][k][p][q] = nextInt();
                    }
                }
            }
        }
    }
    return buf;

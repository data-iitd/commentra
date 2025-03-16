
// Package main defines the entry point of the program.
package main;

// Importing necessary libraries for the program.
import (
    "bufio";
    "errors";
    "fmt";
    "io";
    "math";
    "os";
    "strconv";
)



// Constants used in the program.
public class Main {
    public static final int MOD = 1000000000 + 7;
    public static final int ALPHABET_NUM = 26;
    public static final int INF_INT64 = Integer.MAX_VALUE;
    public static final long INF_BIT60 = 1 << 60;
    public static final int INF_INT32 = Integer.MAX_VALUE;
    public static final int INF_BIT30 = 1 << 30;
    public static final int NIL = -1;
    public static final int WHITE = 0;
    public static final int GRAY = 1;
    public static final int BLACK = 2;

    // Global variables used in the program.
    public static char[] S;
    public static int x, y;
    public static boolean[][] dpx, dpy;

    // Main function reads input, processes the data, and prints the result.
    public static void main(String[] args) {
        S = ReadRuneSlice();
        x, y = ReadInt2();

        int[] F = new int[S.length];
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
        PrintfDebug("%v\n", F);

        int[] evens = new int[S.length/2 + 1];
        int[] odds = new int[S.length/2 + 1];
        for (int i = 0; i < S.length; i++) {
            if (i % 2 == 0) {
                evens[i/2] = F[i];
            } else {
                odds[i/2] = F[i];
            }
        }

        dpx = new boolean[evens.length + 1][18001];
        dpy = new boolean[odds.length + 1][18001];
        dpx[0][10000] = true;
        dpy[0][10000] = true;
        for (int i = 0; i < evens.length; i++) {
            int val = evens[i];
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
                }
                if (j - val >= 2000 && i!= 0) {
                    dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
                }
            }
        }
        for (int i = 0; i < odds.length; i++) {
            int val = odds[i];
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
                }
                if (j - val >= 2000) {
                    dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
                }
            }
        }

        if (dpx[evens.length][x + 10000] && dpy[odds.length][y + 10000]) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    // ReadString returns a WORD string.
    public static String ReadString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static char ReadChar() {
        return ReadString().charAt(0);
    }

    public static int ReadInt() {
        return Integer.parseInt(ReadString());
    }

    public static int[] ReadIntArr(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ReadInt();
        }
        return res;
    }

    public static int[][] ReadIntArr2(int n, int m) {
        int[][] res = new int[n][m];
        for (int i = 0; i < n; i++) {
            res[i] = ReadIntArr(m);
        }
        return res;
    }

    public static long ReadLong() {
        return Long.parseLong(ReadString());
    }

    public static long[] ReadLongArr(int n) {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = ReadLong();
        }
        return res;
    }

    public static long[][] ReadLongArr2(int n, int m) {
        long[][] res = new long[n][m];
        for (int i = 0; i < n; i++) {
            res[i] = ReadLongArr(m);
        }
        return res;
    }

    public static float ReadFloat() {
        return Float.parseFloat(ReadString());
    }

    public static float[] ReadFloatArr(int n) {
        float[] res = new float[n];
        for (int i = 0; i < n; i++) {
            res[i] = ReadFloat();
        }
        return res;
    }

    public static float[][] ReadFloatArr2(int n, int m) {
        float[][] res = new float[n][m];
        for (int i = 0; i < n; i++) {
            res[i] = ReadFloatArr(m);
        }
        return res;
    }

    public static double ReadDouble() {
        return Double.parseDouble(ReadString());
    }

    public static double[] ReadDoubleArr(int n) {
        double[] res = new double[n];
        for (int i = 0; i < n; i++) {
            res[i] = ReadDouble();
        }
        return res;
    }

    public static double[][] ReadDoubleArr2(int n, int m) {
        double[][] res = new double[n][m];
        for (int i = 0; i < n; i++) {
            res[i] = ReadDoubleArr(m);
        }
        return res;
    }

    public static void Read(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = ReadInt();
        }
    }

    public static void Read(long[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = ReadLong();
        }
    }

    public static void Read(float[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = ReadFloat();
        }
    }

    public static void Read(double[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = ReadDouble();
        }
    }

    public static void Read(int[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            Read(arr[i]);
        }
    }

    public static void Read(long[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            Read(arr[i]);
        }
    }

    public static void Read(float[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            Read(arr[i]);
        }
    }

    public static void Read(double[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            Read(arr[i]);
        }
    }

    public static void Print(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i!= arr.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static void Print(long[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i!= arr.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static void Print(float[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i!= arr.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static void Print(double[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i!= arr.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static void Print(int[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            Print(arr[i]);
        }
    }

    public static void Print(long[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            Print(arr[i]);
        }
    }

    public static void Print(float[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            Print(arr[i]);
        }
    }

    public static void Print(double[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            Print(arr[i]);
        }
    }

    public static void Print(String str) {
        System.out.print(str);
    }

    public static void Print(char c) {
        System.out.print(c);
    }

    public static void Print(int num) {
        System.out.print(num);
    }

    public static void Print(long num) {
        System.out.print(num);
    }

    public static void Print(float num) {
        System.out.print(num);
    }

    public static void Print(double num) {
        System.out.print(num);
    }

    public static void Print(boolean b) {
        System.out.print(b);
    }

    public static void Print(char[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
        }
        System.out.println();
    }

    public static void Print(String[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i!= arr.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static void Printf(String format, Object... args) {
        System.out.printf(format, args);
    }

    public static void Printf(Locale l, String format, Object... args) {
        System.out.printf(l, format, args);
    }

    public static void Println(String str) {
        System.out.println(str);
    }

    public static void Println(char c) {
        System.out.println(c);
    }

    public static void Println(int num) {
        System.out.println(num);
    }

    public static void Println(long num) {
        System.out.println(num);
    }

    public static void Println(float num) {
        System.out.println(num);
    }

    public static void Println(double num) {
        System.out.println(num);
    }

    public static void Println(boolean b) {
        System.out.println(b);
    }

    public static void Println(char[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
        }
        System.out.println();
    }

    public static void Println(String[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i!= arr.length - 1) {

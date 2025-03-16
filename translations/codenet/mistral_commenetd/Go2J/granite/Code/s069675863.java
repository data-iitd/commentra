
/*
URL:
https://atcoder.jp/contests/abc082/tasks/arc087_b
*/

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()
//i := ReadInt()
//X := ReadIntSlice(n)
//S := ReadruneSlice()
//a := ReadFloat64()
//A := ReadFloat64Slice(n)

//str := ZeroPaddingRuneSlice(num, 32)
//str := PrintIntsLine(X...)

/*******************************************************************/

public class s069675863{
    // Read a string from the standard input
    public static String ReadString() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Parse two integers from the string and assign them to the variables x and y
    public static void ReadInt2(String s, int[] x, int[] y) {
        Scanner scanner = new Scanner(s);
        x[0] = scanner.nextInt();
        y[0] = scanner.nextInt();
    }

    // Read an integer from the standard input
    public static int ReadInt() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Read an integer array with size n from the standard input
    public static int[] ReadIntSlice(int n) {
        int[] A = new int[n];
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        return A;
    }

    // Read a rune slice from the standard input
    public static char[] ReadCharSlice() {
        return ReadString().toCharArray();
    }

    // Read a float64 from the standard input
    public static double ReadFloat64() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextDouble();
    }

    // Read a float64 array with size n from the standard input
    public static double[] ReadFloat64Slice(int n) {
        double[] A = new double[n];
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextDouble();
        }
        return A;
    }

    // ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
    // For debugging use.
    public static char[] ZeroPaddingRuneSlice(int n, int digitsNum) {
        String sn = Integer.toBinaryString(n);

        int residualLength = digitsNum - sn.length();
        if (residualLength <= 0) {
            return sn.toCharArray();
        }

        char[] zeros = new char[residualLength];
        Arrays.fill(zeros, '0');

        char[] res = new char[residualLength + sn.length()];
        System.arraycopy(zeros, 0, res, 0, residualLength);
        System.arraycopy(sn.toCharArray(), 0, res, residualLength, sn.length());

        return res;
    }

    // Strtoi is a wrapper of Integer.parseInt().
    // If Integer.parseInt() returns an error, Strtoi calls panic.
    public static int Strtoi(String s) {
        try {
            return Integer.parseInt(s);
        } catch (NumberFormatException e) {
            throw new RuntimeException(e);
        }
    }

    // PrintIntsLine returns integers string delimited by a space.
    public static String PrintIntsLine(int[] A) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < A.length; i++) {
            sb.append(A[i]);
            if (i!= A.length - 1) {
                sb.append(' ');
            }
        }
        return sb.toString();
    }

    // PrintIntsLine returns integers string delimited by a space.
    public static String PrintInts64Line(long[] A) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < A.length; i++) {
            sb.append(A[i]);
            if (i!= A.length - 1) {
                sb.append(' ');
            }
        }
        return sb.toString();
    }

    // PrintfDebug is wrapper of System.err.printf().
    public static void PrintfDebug(String format, Object... args) {
        System.err.printf(format, args);
    }

    // PrintfBufStdout is function for output strings to buffered os.Stdout.
    // You may have to call stdout.Flush() finally.
    public static void PrintfBufStdout(String format, Object... args) {
        System.out.printf(format, args);
    }

    public static void main(String[] args) {
        // Read a string from the standard input
        char[] S = ReadCharSlice();

        // Parse two integers from the string and assign them to the variables x and y
        int[] x = new int[1];
        int[] y = new int[1];
        ReadInt2(new String(S), x, y);

        // Initialize a 2D boolean array dpx and dpy with the size of 8000 x 20000
        boolean[][] dpx = new boolean[8000][20000];
        boolean[][] dpy = new boolean[8000][20000];

        // Iterate through the even indices of the F slice and update the dpx array accordingly
        for (int i = 0; i < F.length; i++) {
            updateDPX(i, F[i]);
        }

        // Iterate through the odd indices of the F slice and update the dpy array accordingly
        for (int i = 0; i < F.length; i++) {
            updateDPY(i, F[i]);
        }

        // Check if the boolean values at the indices (len(evens) + 1) and (len(odds) + 1) corresponding to x and y are both true
        if (dpx[F.length][x[0] + 10000] && dpy[F.length][y[0] + 10000]) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    // helper function to update dpx array
    public static void updateDPX(int index, int val) {
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
            }
            if (j - val >= 2000 && index!= 0) {
                dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
            }
        }
    }

    // helper function to update dpy array
    public static void updateDPY(int index, int val) {
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
            }
            if (j - val >= 2000) {
                dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
            }
        }
    }

    // Read an integer array with size n from the standard input
    public static int[] ReadIntSlice(int n) {
        int[] A = new int[n];
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        return A;
    }

    // Read a rune slice from the standard input
    public static char[] ReadCharSlice() {
        return ReadString().toCharArray();
    }

    // Read a float64 array with size n from the standard input
    public static double[] ReadFloat64Slice(int n) {
        double[] A = new double[n];
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextDouble();
        }
        return A;
    }

    // Read an integer from the standard input
    public static int ReadInt() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Read a string from the standard input
    public static String ReadString() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Read a float64 from the standard input
    public static double ReadFloat64() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextDouble();
    }

    // ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
    // For debugging use.
    public static char[] ZeroPaddingRuneSlice(int n, int digitsNum) {
        String sn = Integer.toBinaryString(n);

        int residualLength = digitsNum - sn.length();
        if (residualLength <= 0) {
            return sn.toCharArray();
        }

        char[] zeros = new char[residualLength];
        Arrays.fill(zeros, '0');

        char[] res = new char[residualLength + sn.length()];
        System.arraycopy(zeros, 0, res, 0, residualLength);
        System.arraycopy(sn.toCharArray(), 0, res, residualLength, sn.length());

        return res;
    }

    // Strtoi is a wrapper of Integer.parseInt().
    // If Integer.parseInt() returns an error, Strtoi calls panic.
    public static int Strtoi(String s) {
        try {
            return Integer.parseInt(s);
        } catch (NumberFormatException e) {
            throw new RuntimeException(e);
        }
    }

    // PrintIntsLine returns integers string delimited by a space.
    public static String PrintIntsLine(int[] A) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < A.length; i++) {
            sb.append(A[i]);
            if (i!= A.length - 1) {
                sb.append(' ');
            }
        }
        return sb.toString();
    }

    // PrintfDebug is wrapper of System.err.printf().
    public static void PrintfDebug(String format, Object... args) {
        System.err.printf(format, args);
    }

    // PrintfBufStdout is function for output strings to buffered os.Stdout.
    // You may have to call stdout.Flush() finally.
    public static void PrintfBufStdout(String format, Object... args) {
        PrintfBufStdout(format, args);
        System.out.printf(format, args);
        System.out.flush();
    }

    // ReadInt2 is function for parsing two integers from the standard input.
    public static void ReadInt2(String s, int[] x, int[] y) {
        Scanner scanner = new Scanner(s);
        x[0] = scanner.nextInt();
        y[0] = scanner.nextInt();
    }

    // ReadIntSlice returns an integer array with size n from the standard input.
    public static int[] ReadIntSlice(int n) {
        int[] A = new int[n];
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        return
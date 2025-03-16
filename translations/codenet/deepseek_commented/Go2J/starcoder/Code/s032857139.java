
// Package main defines the entry point of the application.
package main;

// Import necessary packages for input/output, mathematical operations, and sorting.
import (
    "bufio";
    "errors";
    "fmt";
    "io";
    "math";
    "os";
    "sort";
    "strconv";
    "strings";
)



// I/O functions for reading input efficiently.
var (
    ReadString func() string;
    stdout     *bufio.Writer;
)

public class Main {
    public static void main(String[] args) {
        ReadString = newReadString(System.in);
        stdout = new bufio.Writer(System.out);

        main();

        stdout.flush();
        stdout.close();
    }

    public static String readString() throws IOException {
        if (!isStringStreamOpen) {
            isStringStreamOpen = true;
            stringStream = new BufferedReader(new InputStreamReader(System.in));
        }
        return stringStream.readLine();
    }

    public static String[] readStringArray() throws IOException {
        if (!isStringArrayStreamOpen) {
            isStringArrayStreamOpen = true;
            stringArrayStream = new BufferedReader(new InputStreamReader(System.in));
        }
        return stringStream.readLine().split(" ");
    }

    public static int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    public static int[] readIntArray() throws IOException {
        String[] s = readStringArray();
        int[] res = new int[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Integer.parseInt(s[i]);
        }
        return res;
    }

    public static long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    public static long[] readLongArray() throws IOException {
        String[] s = readStringArray();
        long[] res = new long[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Long.parseLong(s[i]);
        }
        return res;
    }

    public static double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    public static double[] readDoubleArray() throws IOException {
        String[] s = readStringArray();
        double[] res = new double[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Double.parseDouble(s[i]);
        }
        return res;
    }

    public static void println(Object... objects) {
        StringBuilder sb = new StringBuilder();
        for (Object object : objects) {
            sb.append(object);
        }

        System.out.println(sb.toString());
    }

    public static void print(Object... objects) {
        StringBuilder sb = new StringBuilder();
        for (Object object : objects) {
            sb.append(object);
        }

        System.out.print(sb.toString());
    }

    public static void printf(String format, Object... objects) {
        System.out.printf(format, objects);
    }

    public static void flush() throws IOException {
        if (stdout!= null) {
            stdout.flush();
        }
    }

    public static void close() throws IOException {
        if (stdout!= null) {
            stdout.close();
        }
    }

    private static String newReadString(InputStream inputStream) {
        return new BufferedReader(new InputStreamReader(inputStream)).readLine();
    }

    private static boolean isStringStreamOpen = false;
    private static boolean isStringArrayStreamOpen = false;
    private static BufferedReader stringStream = null;
    private static BufferedReader stringArrayStream = null;
}



// Utility functions for dynamic programming.
public class Main {
    public static void main(String[] args) {
        int n, x;
        int[] A;
        n = ReadInt();
        x = ReadInt();
        A = ReadIntSlice(n);

        Arrays.sort(A);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
            } else {
                break;
            }
        }
        if (ans == n && x > 0) {
            ans--;
        }
        println(ans);
    }

    public static int ReadInt() {
        return Integer.parseInt(readString());
    }

    public static int[] ReadIntSlice(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ReadInt();
        }
        return res;
    }

    public static String readString() throws IOException {
        if (!isStringStreamOpen) {
            isStringStreamOpen = true;
            stringStream = new BufferedReader(new InputStreamReader(System.in));
        }
        return stringStream.readLine();
    }

    public static String[] readStringArray() throws IOException {
        if (!isStringArrayStreamOpen) {
            isStringArrayStreamOpen = true;
            stringArrayStream = new BufferedReader(new InputStreamReader(System.in));
        }
        return stringStream.readLine().split(" ");
    }

    public static int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    public static int[] readIntArray() throws IOException {
        String[] s = readStringArray();
        int[] res = new int[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Integer.parseInt(s[i]);
        }
        return res;
    }

    public static long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    public static long[] readLongArray() throws IOException {
        String[] s = readStringArray();
        long[] res = new long[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Long.parseLong(s[i]);
        }
        return res;
    }

    public static double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    public static double[] readDoubleArray() throws IOException {
        String[] s = readStringArray();
        double[] res = new double[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Double.parseDouble(s[i]);
        }
        return res;
    }

    public static void println(Object... objects) {
        StringBuilder sb = new StringBuilder();
        for (Object object : objects) {
            sb.append(object);
        }

        System.out.println(sb.toString());
    }

    public static void print(Object... objects) {
        StringBuilder sb = new StringBuilder();
        for (Object object : objects) {
            sb.append(object);
        }

        System.out.print(sb.toString());
    }

    public static void printf(String format, Object... objects) {
        System.out.printf(format, objects);
    }

    public static void flush() throws IOException {
        if (stdout!= null) {
            stdout.flush();
        }
    }

    public static void close() throws IOException {
        if (stdout!= null) {
            stdout.close();
        }
    }

    private static String newReadString(InputStream inputStream) {
        return new BufferedReader(new InputStreamReader(inputStream)).readLine();
    }

    private static boolean isStringStreamOpen = false;
    private static boolean isStringArrayStreamOpen = false;
    private static BufferedReader stringStream = null;
    private static BufferedReader stringArrayStream = null;
}



// Arithmetic functions for mathematical operations.
public class Main {
    public static void main(String[] args) {
        int n, x;
        int[] A;
        n = ReadInt();
        x = ReadInt();
        A = ReadIntSlice(n);

        Arrays.sort(A);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
            } else {
                break;
            }
        }
        if (ans == n && x > 0) {
            ans--;
        }
        println(ans);
    }

    public static int ReadInt() {
        return Integer.parseInt(readString());
    }

    public static int[] ReadIntSlice(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ReadInt();
        }
        return res;
    }

    public static String readString() throws IOException {
        if (!isStringStreamOpen) {
            isStringStreamOpen = true;
            stringStream = new BufferedReader(new InputStreamReader(System.in));
        }
        return stringStream.readLine();
    }

    public static String[] readStringArray() throws IOException {
        if (!isStringArrayStreamOpen) {
            isStringArrayStreamOpen = true;
            stringArrayStream = new BufferedReader(new InputStreamReader(System.in));
        }
        return stringStream.readLine().split(" ");
    }

    public static int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    public static int[] readIntArray() throws IOException {
        String[] s = readStringArray();
        int[] res = new int[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Integer.parseInt(s[i]);
        }
        return res;
    }

    public static long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    public static long[] readLongArray() throws IOException {
        String[] s = readStringArray();
        long[] res = new long[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Long.parseLong(s[i]);
        }
        return res;
    }

    public static double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    public static double[] readDoubleArray() throws IOException {
        String[] s = readStringArray();
        double[] res = new double[s.length];
        for (int i = 0; i < s.length; i++) {
            res[i] = Double.parseDouble(s[i]);
        }
        return res;
    }

    public static void println(Object... objects) {
        StringBuilder sb = new StringBuilder();
        for (Object object : 
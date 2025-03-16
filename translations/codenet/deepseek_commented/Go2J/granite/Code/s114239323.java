
import java.util.*;

public class s114239323{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] h = new int[N];
        for (int i = 0; i < N; i++) {
            h[i] = scanner.nextInt();
        }
        int[] dp = new int[N];
        dp[1] = Math.abs(h[0] - h[1]);
        for (int i = 2; i < N; i++) {
            dp[i] = Math.min(dp[i - 1] + Math.abs(h[i] - h[i - 1]), dp[i - 2] + Math.abs(h[i] - h[i - 2]));
        }
        System.out.println(dp[N - 1]);
    }
}

// Utility function to find the absolute value of an integer
public static int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Utility function to find the maximum value in a slice of integers
public static int max(int[] a) {
    int r = a[0];
    for (int i = 0; i < a.length; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a slice of integers
public static int min(int[] a) {
    int r = a[0];
    for (int i = 0; i < a.length; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a slice of integers
public static int sum(int[] a) {
    int r = 0;
    for (int i = 0; i < a.length; i++) {
        r += a[i];
    }
    return r;
}

// Pair struct to represent a pair of integers
public static class Pair implements Comparable<Pair> {
    public int a, b;

    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public int compareTo(Pair o) {
        return this.b - o.b;
    }
}

// Variable to hold the nextReader function
private static java.util.function.Supplier<String> nextReader;

// Initializes the nextReader function
static {
    nextReader = s114239323::newScanner;
}

// newScanner function to create a new scanner for reading input
private static java.util.Scanner newScanner() {
    return new java.util.Scanner(System.in);
}

// nextString function to read the next string
private static String nextString() {
    return nextReader.get();
}

// nextInt64 function to read the next 64-bit integer
private static long nextInt64() {
    return Long.parseLong(nextString());
}

// nextInt function to read the next integer
private static int nextInt() {
    return Integer.parseInt(nextString());
}

// nextInts function to read a slice of integers of length N
private static int[] nextInts(int n) {
    int[] r = new int[n];
    for (int i = 0; i < n; i++) {
        r[i] = nextInt();
    }
    return r;
}

// nextStrings function to read a slice of strings of length N
private static String[] nextStrings(int n) {
    String[] r = new String[n];
    for (int i = 0; i < n; i++) {
        r[i] = nextString();
    }
    return r;
}

// nextFloat64 function to read the next float64
private static double nextFloat64() {
    return Double.parseDouble(nextString());
}

// Translate the above Java code to Python and end with comment "
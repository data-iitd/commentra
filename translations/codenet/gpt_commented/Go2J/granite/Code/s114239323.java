
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

/* templates */

// Max function returns the maximum value from a slice of integers
public static int Max(int[] a) {
    int r = a[0];
    for (int i = 0; i < a.length; i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Min function returns the minimum value from a slice of integers
public static int Min(int[] a) {
    int r = a[0];
    for (int i = 0; i < a.length; i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Sum function calculates the sum of a slice of integers
public static int Sum(int[] a) {
    int r = 0;
    for (int i = 0; i < a.length; i++) {
        r += a[i];
    }
    return r;
}

// Abs function returns the absolute value of an integer
public static int Abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Pair struct represents a pair of integers
public static class Pair {
    public int a, b;

    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

// Pairs is a slice of Pair
public static class Pairs implements Comparable<Pairs> {
    public int a, b;

    public Pairs(int a, int b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public int compareTo(Pairs o) {
        if (this.b == o.b) {
            return this.a - o.a;
        }
        return this.b - o.b;
    }
}

// nextInt reads the next int from input
public static int nextInt() {
    return scanner.nextInt();
}

// nextInts reads n integers from input and returns them as a slice
public static int[] nextInts(int n) {
    int[] r = new int[n];
    for (int i = 0; i < n; i++) {
        r[i] = scanner.nextInt();
    }
    return r;
}

// nextString reads the next string from input
public static String nextString() {
    return scanner.next();
}

// nextStrings reads n strings from input and returns them as a slice
public static String[] nextStrings(int n) {
    String[] r = new String[n];
    for (int i = 0; i < n; i++) {
        r[i] = scanner.next();
    }
    return r;
}

// nextInt64 reads the next int64 from input
public static long nextInt64() {
    return scanner.nextLong();
}

// nextFloat64 reads the next float64 from input
public static double nextFloat64() {
    return scanner.nextDouble();
}

// nextLine reads the next line from input
public static String nextLine() {
    return scanner.nextLine();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBool reads the next bool from input
public static boolean nextBool() {
    return scanner.nextBoolean();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nextLine().getBytes();
}

// nextBytes reads the next line from input and returns it as a byte slice
public static byte[] nextBytes() {
    return scanner.nex
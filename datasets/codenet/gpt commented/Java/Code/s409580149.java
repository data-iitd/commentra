import java.io.*;
import java.util.*;

public class Main {
    static int n, a[];
    static double dp[][][];

    // Main solving function
    static void solve() {
        // Read the number of elements
        n = ni();
        // Read the array of elements
        a = na(n);
        // Initialize the 3D DP array with dimensions (n+1) x (n+1) x (n+1)
        dp = new double[n + 1][n + 1][n + 1];
        // Fill the DP array with -1 to indicate uncomputed states
        for (int i = 0; i < n + 1; i++) fill(dp[i], -1);
        // Base case: no elements processed results in 0
        dp[0][0][0] = 0;
        // Count occurrences of each type in the array
        int cnt[] = new int[3];
        for (int i = 0; i < n; i++) {
            cnt[a[i] - 1]++;
        }
        // Calculate the answer using the recursive function
        double ans = rec(cnt[0], cnt[1], cnt[2]);
        // Output the result
        out.println(ans);
    }

    // Recursive function to compute expected value
    static double rec(int i, int j, int k) {
        // Return cached result if already computed
        if (dp[i][j][k] != -1) return dp[i][j][k];
        double ret = 0;
        // Calculate probabilities based on the current counts
        double p = ((double) i + j + k) / n;
        double pi = (double) i / n;
        double pj = (double) j / n;
        double pk = (double) k / n;
        // Update expected value
        ret += 1 / p;
        // Recursive calls for each case
        if (i > 0) ret += pi / p * rec(i - 1, j, k); // Case when taking from type 1
        if (j > 0) ret += pj / p * rec(i + 1, j - 1, k); // Case when taking from type 2
        if (k > 0) ret += pk / p * rec(i, j + 1, k - 1); // Case when taking from type 3
        // Cache the computed result
        return dp[i][j][k] = ret;
    }

    // Constants for various purposes
    static final long mod = (long) 1e9 + 7; // Modulo constant
    static final int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 }; // Directions for 4-way movement
    static final int[] dx8 = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy8 = { -1, 0, 1, -1, 1, -1, 0, 1 }; // Directions for 8-way movement
    static final int inf = Integer.MAX_VALUE / 2; // Infinity constant for int
    static final long linf = Long.MAX_VALUE / 3; // Infinity constant for long
    static final double dinf = Double.MAX_VALUE / 3; // Infinity constant for double
    static final double eps = 1e-10; // Epsilon for floating-point comparisons
    static final double pi = Math.PI; // Pi constant
    static StringBuilder sb = new StringBuilder(); // StringBuilder for output
    static InputStream is; // Input stream for reading
    static PrintWriter out; // Output writer
    static String INPUT = ""; // Input string

    // Utility functions for reversing arrays
    static void reverse(int ar[]) {
        int len = ar.length;
        for (int i = 0; i < len / 2; i++) {
            int t = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = t;
        }
    }

    static void reverse(long ar[]) {
        int len = ar.length;
        for (int i = 0; i < len / 2; i++) {
            long t = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = t;
        }
    }

    static void reverse(double ar[]) {
        int len = ar.length;
        for (int i = 0; i < len / 2; i++) {
            double t = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = t;
        }
    }

    static void reverse(char ar[]) {
        int len = ar.length;
        for (int i = 0; i < len / 2; i++) {
            char t = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = t;
        }
    }

    // Function to reverse a string
    static String getReverse(String s) {
        char c[] = s.toCharArray();
        reverse(c);
        s = String.valueOf(c);
        return s;
    }

    // Generic reverse function for lists
    static <T> void reverse(List<T> ls) {
        int sz = ls.size();
        for (int i = 0; i < sz / 2; i++) {
            T t = ls.get(i);
            ls.set(i, ls.get(sz - 1 - i));
            ls.set(sz - 1 - i, t);
        }
    }

    // Generic reverse function for arrays
    static <T> void reverse(T[] ar) {
        int len = ar.length;
        for (int i = 0; i < len / 2; i++) {
            T t = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = t;
        }
    }

    // Function to append a newline to StringBuilder
    static void sbnl() {
        sb.append("\n");
    }

    // Binary search utility functions
    static int lowerBound(int[] a, int x) {
        int l = -1, r = a.length;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (a[c] < x) {
                l = c;
            } else {
                r = c;
            }
        }
        return r;
    }

    static int upperBound(int[] a, int x) {
        int l = -1, r = a.length;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (a[c] <= x) {
                l = c;
            } else {
                r = c;
            }
        }
        return r;
    }

    // Additional binary search functions for long and double types
    static int rlowerBound(int[] a, int x) {
        int l = -1, r = a.length;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (a[c] > x) {
                l = c;
            } else {
                r = c;
            }
        }
        return r;
    }

    static int rupperBound(int[] a, int x) {
        int l = -1, r = a.length;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (a[c] >= x) {
                l = c;
            } else {
                r = c;
            }
        }
        return r;
    }

    // Similar binary search functions for long arrays
    static int lowerBound(long[] a, long x) {
        int l = -1, r = a.length;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (a[c] < x) {
                l = c;
            } else {
                r = c;
            }
        }
        return r;
    }

    static int upperBound(long[] a, long x) {
        int l = -1, r = a.length;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (a[c] <= x) {
                l = c;
            } else {
                r = c;
            }
        }
        return r;
    }

    // Similar binary search functions for double arrays
    static int lowerBound(double[] a, double x) {
        int l = -1, r = a.length;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (a[c] < x) {
                l = c;
            } else {
                r = c;
            }
        }
        return r;
    }

    static int upperBound(double[] a, double x) {
        int l = -1, r = a.length;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (a[c] <= x) {
                l = c;
            } else {
                r = c;
            }
        }
        return r;
    }

    // Concatenation utility functions for arrays
    static int[] concat(int x, int arr[]) {
        int ret[] = new int[arr.length + 1];
        System.arraycopy(arr, 0, ret, 1, ret.length - 1);
        ret[0] = x;
        return ret;
    }

    static int[] concat(int arr[], int x) {
        int ret[] = new int[arr.length + 1];
        System.arraycopy(arr, 0, ret, 0, ret.length - 1);
        ret[ret.length - 1] = x;
        return ret;
    }

    // Utility functions for max and min calculations
    static int max(int x, int y) {
        return Math.max(x, y);
    }

    static int min(int x, int y) {
        return Math.min(x, y);
    }

    static long max(long x, long y) {
        return Math.max(x, y);
    }

    static long min(long x, long y) {
        return Math.min(x, y);
    }

    static double max(double x, double y) {
        return Math.max(x, y);
    }

    static double min(double x, double y) {
        return Math.min(x, y);
    }

    // Sorting utility functions
    static void sort(int[] ar) {
        Arrays.sort(ar);
    }

    static void sort(long[] ar) {
        Arrays.sort(ar);
    }

    static void sort(double[] ar) {
        Arrays.sort(ar);
    }

    static void sort(char[] ar) {
        Arrays.sort(ar);
    }

    // Function to fill arrays with a specific value
    static void fill(int arr[], int x) {
        Arrays.fill(arr, x);
    }

    static void fill(long arr[], long x) {
        Arrays.fill(arr, x);
    }

    static void fill(double arr[], double x) {
        Arrays.fill(arr, x);
    }

    // Modular arithmetic functions
    static long plus(long x, long y) {
        long res = (x + y) % mod;
        return res < 0 ? res + mod : res;
    }

    static long sub(long x, long y) {
        long res = (x - y) % mod;
        return res < 0 ? res + mod : res;
    }

    static long mul(long x, long y) {
        long res = (x * y) % mod;
        return res < 0 ? res + mod : res;
    }

    static long div(long x, long y) {
        long res = x * pow(y, mod - 2) % mod;
        return res < 0 ? res + mod : res;
    }

    static long pow(long x, long y) {
        if (y < 0)
            return 0;
        if (y == 0)
            return 1;
        if (y % 2 == 1)
            return (x * pow(x, y - 1)) % mod;
        long root = pow(x, y / 2);
        return root * root % mod;
    }

    // Main function to execute the program
    public static void main(String[] args) throws Exception {
        // Initialize input and output streams
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);
        // Call the solve function to process the input
        solve();
        // Flush the output
        out.flush();
    }

    // Input reading utilities
    private static byte[] inbuf = new byte[1024];
    static int lenbuf = 0, ptrbuf = 0;

    private static int readByte() {
        if (lenbuf == -1)
            throw new InputMismatchException();
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {
                lenbuf = is.read(inbuf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (lenbuf <= 0)
                return -1;
        }
        return inbuf[ptrbuf++];
    }

    private static boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    private static int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b))
            ;
        return b;
    }

    // Reading various types of input
    private static int ni() {
        int num = 0, b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
            ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private static int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = ni();
        return a;
    }
}

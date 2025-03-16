import java.io.*;
import java.util.*;

public class Main {
    // Main class with a static solve method

    static void solve() {
        // Read next string from input
        String tmp = ns();
        // Convert the string to a char array
        char s[] = tmp.toCharArray();
        // Get the length of the char array
        int n = s.length;
        // Initialize answer and counter variables
        int ans = 0, cnt = 0;
        // Iterate through the char array
        for (int i = 0; i < n; i++) {
            // If current character is 'S', increment counter
            if (s[i] == 'S') {
                cnt++;
            }
            // If current character is not 'S', check if counter is zero
            else if (cnt == 0) {
                continue;
            }
            // If counter is not zero, increment answer and decrement counter
            else {
                ans++;
                cnt--;
            }
        }
        // Print the answer
        out.println(n - 2 * ans);
    }

    // Constants and libraries
    static final long mod = (long) 1e9 + 7;
    static final int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
    static final int[] dx8 = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy8 = { -1, 0, 1, -1, 1, -1, 0, 1 };
    static final int inf = Integer.MAX_VALUE / 2;
    static final long linf = Long.MAX_VALUE / 3;
    static final double dinf = Double.MAX_VALUE / 3;
    static final double eps = 1e-10;
    static final double pi = Math.PI;
    static StringBuilder sb = new StringBuilder();
    static InputStream is;
    static PrintWriter out;
    static String INPUT = "";

    // Helper methods
    static void reverse(int ar[]) {
        // Reverse an integer array
    }

    static void reverse(long ar[]) {
        // Reverse a long array
    }

    static void reverse(double ar[]) {
        // Reverse a double array
    }

    static void reverse(char ar[]) {
        // Reverse a char array
    }

    static String getReverse(String s) {
        // Get the reverse of a given string
        char c[] = s.toCharArray();
        reverse(c);
        return new String(c);
    }

    static <T> void reverse(List<T> ls) {
        // Reverse a given list
    }

    static <T> void reverse(T[] ar) {
        // Reverse a given array
    }

    static void sbnl() {
        // Append a newline character to StringBuilder
    }

    // Helper methods for binary search
    static int lowerBound(int[] a, int x) {
        // Find the index of the first element greater than or equal to x
    }

    static int upperBound(int[] a, int x) {
        // Find the index of the first element strictly greater than x
    }

    static int rlowerBound(int[] a, int x) {
        // Find the index of the last element less than or equal to x
    }

    static int rupperBound(int[] a, int x) {
        // Find the index of the last element strictly less than x
    }

    static int lowerBound(long[] a, long x) {
        // Find the index of the first element greater than or equal to x
    }

    static int upperBound(long[] a, long x) {
        // Find the index of the first element strictly greater than x
    }

    static int rlowerBound(long[] a, long x) {
        // Find the index of the last element less than or equal to x
    }

    static int rupperBound(long[] a, long x) {
        // Find the index of the last element strictly less than x
    }

    static int lowerBound(double[] a, double x) {
        // Find the index of the first element greater than or equal to x
    }

    static int upperBound(double[] a, double x) {
        // Find the index of the first element strictly greater than x
    }

    static int rlowerBound(double[] a, double x) {
        // Find the index of the last element less than or equal to x
    }

    static int rupperBound(double[] a, double x) {
        // Find the index of the last element strictly less than x
    }

    static int lowerBound(char[] a, char x) {
        // Find the index of the first element greater than or equal to x
    }

    static int upperBound(char[] a, char x) {
        // Find the index of the first element strictly greater than x
    }

    static int rlowerBound(char[] a, char x) {
        // Find the index of the last element less than or equal to x
    }

    static int rupperBound(char[] a, char x) {
        // Find the index of the last element strictly less than x
    }

    // Helper method for binary search on a list
    static <T> int lowerBound(List<T> ls, T x) throws RuntimeException {
        // Find the index of the first element greater than or equal to x
    }

    static <T> int upperBound(List<T> ls, T x) throws RuntimeException {
        // Find the index of the first element strictly greater than x
    }

    static <T> int rupperBound(List<T> ls, T x) throws RuntimeException {
        // Find the index of the last element strictly less than x
    }

    static <T> int rlowerBound(List<T> ls, T x) {
        // Find the index of the last element less than or equal to x
    }

    // Helper methods for concatenating arrays
    static int[] concat(int x, int arr[]) {
        // Concatenate an integer and an array
    }

    static int[] concat(int arr[], int x) {
        // Concatenate an array and an integer
    }

    static long[] concat(long x, long arr[]) {
        // Concatenate a long and an array
    }

    static long[] concat(long arr[], long x) {
        // Concatenate an array and a long
    }

    // Helper methods for basic arithmetic operations
    static int max(int x, int y) {
        // Find the maximum of two integers
    }

    static int min(int x, int y) {
        // Find the minimum of two integers
    }

    static int max(int x, int y, int z) {
        // Find the maximum of three integers
    }

    static int min(int x, int y, int z) {
        // Find the minimum of three integers
    }

    static long max(long x, long y) {
        // Find the maximum of two longs
    }

    static long min(long x, long y) {
        // Find the minimum of two longs
    }

    static long max(long x, long y, long z) {
        // Find the maximum of three longs
    }

    static long min(long x, long y, long z) {
        // Find the minimum of three longs
    }

    static double max(double x, double y) {
        // Find the maximum of two doubles
    }

    static double min(double x, double y) {
        // Find the minimum of two doubles
    }

    static double max(double x, double y, double z) {
        // Find the maximum of three doubles
    }

    static double min(double x, double y, double z) {
        // Find the minimum of three doubles
    }

    // Helper method for sorting arrays
    static void sort(int[] ar) {
        // Sort an integer array in ascending order
    }

    static void sort(long[] ar) {
        // Sort a long array in ascending order
    }

    static void sort(double[] ar) {
        // Sort a double array in ascending order
    }

    static void sort(char[] ar) {
        // Sort a char array in ascending order
    }

    // Helper method for reversing sorted arrays
    static void rsort(int[] ar) {
        // Reverse the order of a sorted integer array
    }

    static void rsort(long[] ar) {
        // Reverse the order of a sorted long array
    }

    static void rsort(double[] ar) {
        // Reverse the order of a sorted double array
    }

    static void rsort(char[] ar) {
        // Reverse the order of a sorted char array
    }

    // Helper method for filling arrays with a constant value
    static void fill(int arr[], int x) {
        // Fill an integer array with a constant value
    }

    static void fill(long arr[], long x) {
        // Fill a long array with a constant value
    }

    static void fill(boolean arr[], boolean x) {
        // Fill a boolean array with a constant value
    }

    static void fill(double arr[], double x) {
        // Fill a double array with a constant value
    }

    static void fill(int arr[][], int x) {
        // Fill a 2D integer array with a constant value
    }

    static void fill(long arr[][], long x) {
        // Fill a 2D long array with a constant value
    }

    static void fill(double arr[][], double x) {
        // Fill a 2D double array with a constant value
    }

    static void fill(boolean arr[][], boolean x) {
        // Fill a 2D boolean array with a constant value
    }

    // Helper methods for modular arithmetic operations
    static long plus(long x, long y) {
        // Perform modular addition of two longs
    }

    static long sub(long x, long y) {
        // Perform modular subtraction of two longs
    }

    static long mul(long x, long y) {
        // Perform modular multiplication of two longs
    }

    static long div(long x, long y) {
        // Perform modular division of two longs
    }

    static long pow(long x, long y) {
        // Perform modular exponentiation of two longs
    }

    // Main method
    public static void main(String[] args) throws Exception {
        // Initialize input and output streams
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);
        // Call the solve method
        solve();
        // Flush the output stream
        out.flush();
    }
}

package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Read the number of elements
        int N = nextInt();
        // Read the heights into a slice
        int[] h = nextInts(N);

        // Initialize a dynamic programming slice to store minimum costs
        int[] dp = new int[N];
        for (int i = 0; i < N; i++) {
            dp[i] = 0; // Set initial values to zero
        }

        // Base case: cost to jump from the first to the second height
        dp[1] = Math.abs(h[0] - h[1]);

        // Fill the dp slice with minimum costs for each position
        for (int i = 2; i < N; i++) {
            dp[i] = Math.min(dp[i-1] + Math.abs(h[i] - h[i-1]), dp[i-2] + Math.abs(h[i] - h[i-2]));
        }

        // Output the minimum cost to reach the last height
        System.out.println(dp[N-1]);
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
        int a, b;
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    // Pairs is a slice of Pair
    public static class Pairs extends ArrayList<Pair> {
        public Pairs() {
            super();
        }
        public Pairs(int... a) {
            super();
            for (int i = 0; i < a.length; i += 2) {
                add(new Pair(a[i], a[i+1]));
            }
        }
    }

    // nextReader is a function that reads input from standard input
    public static String nextReader() {
        try {
            return new Scanner(System.in).nextLine();
        } catch (Exception e) {
            return "";
        }
    }

    // nextString reads the next string from input
    public static String nextString() {
        return nextReader();
    }

    // nextInt64 reads the next int64 from input
    public static long nextInt64() {
        return Long.parseLong(nextReader());
    }

    // nextInt reads the next int from input
    public static int nextInt() {
        return Integer.parseInt(nextReader());
    }

    // nextInts reads n integers from input and returns them as a slice
    public static int[] nextInts(int n) {
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = nextInt();
        }
        return r;
    }

    // nextStrings reads n strings from input and returns them as a slice
    public static String[] nextStrings(int n) {
        String[] r = new String[n];
        for (int i = 0; i < n; i++) {
            r[i] = nextString();
        }
        return r;
    }

    // nextFloat64 reads the next float64 from input
    public static double nextFloat64() {
        return Double.parseDouble(nextReader());
    }

}


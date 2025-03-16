
// Package main defines the entry point of the application.
package main

// Import necessary packages for input/output, mathematical operations, and sorting.
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;



// I/O functions for reading input efficiently.
static class FastScanner {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer("");

    String next() {
        while (!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }
}



// Utility functions for dynamic programming.
static class Utils {
    static boolean chmin(int[] arr, int target) {
        if (arr[0] > target) {
            arr[0] = target;
            return true;
        }
        return false;
    }

    static boolean chmax(int[] arr, int target) {
        if (arr[0] < target) {
            arr[0] = target;
            return true;
        }
        return false;
    }

    static int getNthBit(int num, int nth) {
        return num >> nth & 1;
    }
}



// Arithmetic functions for mathematical operations.
static class Arithmetic {
    static int max(int... integers) {
        int m = integers[0];
        for (int i = 1; i < integers.length; i++) {
            if (m < integers[i]) {
                m = integers[i];
            }
        }
        return m;
    }

    static int min(int... integers) {
        int m = integers[0];
        for (int i = 1; i < integers.length; i++) {
            if (m > integers[i]) {
                m = integers[i];
            }
        }
        return m;
    }

    static int ceilInt(int a, int b) {
        return a / b + (a % b != 0 ? 1 : 0);
    }

    static int floorInt(int a, int b) {
        return a / b;
    }

    static int powInt(int a, int e) {
        if (a < 0 || e < 0) {
            throw new RuntimeException("[argument error]: PowInt does not accept negative integers");
        }

        if (e == 0) {
            return 1;
        }

        if (e % 2 == 0) {
            int halfE = e / 2;
            int half = powInt(a, halfE);
            return half * half;
        }

        return a * powInt(a, e - 1);
    }

    static int absInt(int a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    static int gcd(int a, int b) {
        if (a <= 0 || b <= 0) {
            throw new RuntimeException("[argument error]: Gcd only accepts two NATURAL numbers");
        }
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }

        return a;
    }

    static int lcm(int a, int b) {
        if (a <= 0 || b <= 0) {
            throw new RuntimeException("[argument error]: Gcd only accepts two NATURAL numbers");
        }

        return (a / gcd(a, b)) * b;
    }
}



// Utility functions for string manipulation and permutation.
static class StringUtils {
    static String deleteElement(String s, int i) {
        if (i < 0 || s.length() <= i) {
            throw new RuntimeException("[index error]");
        }
        return s.substring(0, i) + s.substring(i + 1);
    }

    static String concat(String s, String t) {
        return s + t;
    }

    static String upperRune(String s) {
        return s.toUpperCase();
    }

    static String lowerRune(String s) {
        return s.toLowerCase();
    }

    static String toggleRune(String s) {
        if (s.length() != 1) {
            throw new RuntimeException("[argument error]: toggleRune only accepts single character string");
        }
        if ('a' <= s.charAt(0) && s.charAt(0) <= 'z') {
            return String.valueOf(s.toUpperCase().charAt(0));
        } else if ('A' <= s.charAt(0) && s.charAt(0) <= 'Z') {
            return String.valueOf(s.toLowerCase().charAt(0));
        } else {
            return s;
        }
    }

    static String toggleString(String s) {
        StringBuilder sb = new StringBuilder(s.length());
        for (int i = 0; i < s.length(); i++) {
            sb.append(toggleRune(s.substring(i, i + 1)));
        }
        return sb.toString();
    }

    static int strtoi(String s) {
        return Integer.parseInt(s);
    }
}



// Functions for generating permutations.
static class Permutation {
    static long factorial(int n) {
        if (n == 0) {
            return 1;
        }

        long res = 1;
        while (n > 0) {
            res *= n;
            n--;
        }
        return res;
    }

    static long[][] permutation(int n) {
        long[][] res = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            res[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }

    static long[][] combination(int n) {
        long[][] res = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            res[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }

    static long[] factorials(int n) {
        long[] res = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            res[i] = factorial(i);
        }
        return res;
    }

    static long[][] permutationWithIndex(int n) {
        long[][] res = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            res[i][0] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }

    static long[][] combinationWithIndex(int n) {
        long[][] res = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            res[i][0] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }

    static long[] factorialsWithIndex(int n) {
        long[] res = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            res[i] = factorial(i);
        }
        return res;
    }

    static long[][][] permutationTriple(int n) {
        long[][][] res = new long[n + 1][][];
        for (int i = 0; i <= n; i++) {
            res[i] = permutation(i);
        }
        return res;
    }

    static long[][][] combinationTriple(int n) {
        long[][][] res = new long[n + 1][][];
        for (int i = 0; i <= n; i++) {
            res[i] = combination(i);
        }
        return res;
    }

    static long[][][] permutationWithIndexTriple(int n) {
        long[][][] res = new long[n + 1][][];
        for (int i = 0; i <= n; i++) {
            res[i] = permutationWithIndex(i);
        }
        return res;
    }

    static long[][][] combinationWithIndexTriple(int n) {
        long[][][] res = new long[n + 1][][];
        for (int i = 0; i <= n; i++) {
            res[i] = combinationWithIndex(i);
        }
        return res;
    }

    static long[][][] factorialsWithIndexTriple(int n) {
        long[][][] res = new long[n + 1][][];
        for (int i = 0; i <= n; i++) {
            res[i] = factorialsWithIndex(i);
        }
        return res;
    }
}



// Functions for generating permutations.
static class Combination {
    static long[] factorials(int n) {
        long[] res = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            res[i] = factorial(i);
        }
        return res;
    }

    static long[] factorialsWithIndex(int n) {
        long[] res = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            res[i] = factorial(i);
        }
        return res;
    }

    static long[][] combination(int n, int k) {
        long[][] res = new long[k][n];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = 0;
            }
        }
        return res;
    }

    static long[][] combinationWithIndex(int n, int k) {
        long[][] res = new long[k][n];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = 0;
            }
        }
        return res;
    }

    static long[][][] combinationTriple(int n, int k) {
        long[][][] res = new long[k][][];
        for (int i = 0; i < k; i++) {
            res[i] = combination(n, k);
        }
        return res;
    }

    static long[][][] combinationWithIndexTriple(int n, int k) {
        long[][][] res = new long[k][][];
        for (int i = 0; i < k; i++) {
            res[i] = combinationWithIndex(n, k);
        }
        return res;
    }

    static long factorial(int n) {
        if (n == 0) {
            return 1;
        }

        long res = 1;
        while (n > 0) {
            res *= n;
            n--;
        }
        return res;
    }

    static long combination(int n, int k) {
        return factorial(n) / (factorial(k) * factorial(n - k));
    }

    static long combinationWithIndex(int n, int k) {
        return factorialWithIndex(n) / (factorialWithIndex(k) * factorialWithIndex(n - k));
    }

    static long factorialWithIndex(int n) {
        if (n == 0) {
            return 1;
        }

        long res = 1;
        for (int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }
}



// Functions for generating per
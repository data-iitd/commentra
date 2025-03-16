
// Package main is the entry point of the program
package main

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // Function to solve the problem
    public static void solve() {
        // Read the number of elements in the array
        int n = getInt();
        // Read the array elements
        int[] as = getIntSlice(n);

        // Initialize an array xs of size n
        int[] xs = new int[n];
        // Iterate through the array as and assign the value xs[i]
        for (int i = 0; i < n; i++) {
            xs[i] = as[i] - i + 1; // Assign the value xs[i] = a - i + 1
        }
        // Sort the array xs in ascending order
        Arrays.sort(xs);

        // Assign the middle element of the sorted array xs to variable b
        int b = xs[n / 2];
        // Initialize variable ans with 0
        int ans = 0;
        // Iterate through the array xs and calculate the absolute difference between each element and b
        for (int x : xs) {
            ans += Math.abs(x - b); // Calculate the absolute difference and add it to ans
        }
        // Print the answer
        System.out.println(ans);
    }

    public static int getInt() {
        // Function to read an integer from standard input
        try {
            return Integer.parseInt(br.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
        return -1;
    }

    public static int[] getIntSlice(int n) {
        // Function to read an array of n integers from standard input
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = getInt(); // Read each integer and assign it to the corresponding index in the array
        }
        return ret;
    }

    public static String getString() {
        // Function to read a string from standard input
        try {
            return br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "";
    }

    public static String[] getStringSlice(int n) {
        // Function to read an array of n strings from standard input
        String[] ret = new String[n];
        for (int i = 0; i < n; i++) {
            ret[i] = getString(); // Read each string and assign it to the corresponding index in the array
        }
        return ret;
    }

    public static int[] getIntArray(int n) {
        // Function to read an array of n integers from standard input
        String[] str = getStringSlice(n);
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = Integer.parseInt(str[i]); // Read each integer and assign it to the corresponding index in the array
        }
        return ret;
    }

    public static long[] getLongArray(int n) {
        // Function to read an array of n long integers from standard input
        String[] str = getStringSlice(n);
        long[] ret = new long[n];
        for (int i = 0; i < n; i++) {
            ret[i] = Long.parseLong(str[i]); // Read each long integer and assign it to the corresponding index in the array
        }
        return ret;
    }

    public static double[] getDoubleArray(int n) {
        // Function to read an array of n double integers from standard input
        String[] str = getStringSlice(n);
        double[] ret = new double[n];
        for (int i = 0; i < n; i++) {
            ret[i] = Double.parseDouble(str[i]); // Read each double integer and assign it to the corresponding index in the array
        }
        return ret;
    }

    public static long getLong() {
        // Function to read a long integer from standard input
        try {
            return Long.parseLong(br.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
        return -1;
    }

    public static double getDouble() {
        // Function to read a double integer from standard input
        try {
            return Double.parseDouble(br.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
        return -1;
    }

    public static String[] getStringArray(int n) {
        // Function to read an array of n strings from standard input
        String[] ret = new String[n];
        for (int i = 0; i < n; i++) {
            ret[i] = getString(); // Read each string and assign it to the corresponding index in the array
        }
        return ret;
    }

    public static long[][] getLongArray2(int n, int m) {
        // Function to read an array of n x m long integers from standard input
        String[] str = getStringSlice(n);
        long[][] ret = new long[n][m];
        for (int i = 0; i < n; i++) {
            String[] str2 = getStringSlice(m);
            for (int j = 0; j < m; j++) {
                ret[i][j] = Long.parseLong(str2[j]); // Read each long integer and assign it to the corresponding index in the array
            }
        }
        return ret;
    }

    public static int[][] getIntArray2(int n, int m) {
        // Function to read an array of n x m integers from standard input
        String[] str = getStringSlice(n);
        int[][] ret = new int[n][m];
        for (int i = 0; i < n; i++) {
            String[] str2 = getStringSlice(m);
            for (int j = 0; j < m; j++) {
                ret[i][j] = Integer.parseInt(str2[j]); // Read each integer and assign it to the corresponding index in the array
            }
        }
        return ret;
    }

    public static double[][] getDoubleArray2(int n, int m) {
        // Function to read an array of n x m double integers from standard input
        String[] str = getStringSlice(n);
        double[][] ret = new double[n][m];
        for (int i = 0; i < n; i++) {
            String[] str2 = getStringSlice(m);
            for (int j = 0; j < m; j++) {
                ret[i][j] = Double.parseDouble(str2[j]); // Read each double integer and assign it to the corresponding index in the array
            }
        }
        return ret;
    }

    public static String[][] getStringArray2(int n, int m) {
        // Function to read an array of n x m strings from standard input
        String[][] ret = new String[n][m];
        for (int i = 0; i < n; i++) {
            String[] str = getStringSlice(m);
            for (int j = 0; j < m; j++) {
                ret[i][j] = str[j]; // Read each string and assign it to the corresponding index in the array
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        // Main function
        solve(); // Call the solve function
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
}


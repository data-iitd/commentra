
// Package main is the entry point of the program
package main

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    // Initialize scanner, reader, and writer
    static Scanner sc = new Scanner(System.in);
    static BufferedReader rdr = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter wt = new PrintWriter(System.out);

    public static void main(String[] args) {
        // Initialize scanner, reader, and writer
        sc.useDelimiter("\\s+");
        int n = nextInt();
        int[] a = nextInts(n);

        // Initialize answer variable
        int ans = 0;

        // Iterate through the array 'a'
        for (int i = 0; i < n; i++) {
            // Initialize left and right indices
            int l = i, r = i + 1;

            // Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
            while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
                r++;
            }

            // Increment the answer variable
            ans++;

            // Update the index 'i' to 'r' for the next iteration
            i = r;
        }

        // Print the answer
        wt.println(ans);
        wt.flush();
    }

    // Helper function to read a single word from the standard input
    static String next() {
        return sc.next();
    }

    // Helper function to read an integer from the standard input
    static int nextInt() {
        return Integer.parseInt(next());
    }

    // Helper function to read float64 from the standard input
    static double nextFloat64() {
        return Double.parseDouble(next());
    }

    // Helper function to read n integers from the standard input
    static int[] nextInts(int n) {
        int[] slice = new int[n];
        for (int i = 0; i < n; i++) {
            slice[i] = nextInt();
        }
        return slice;
    }

    // Helper function to read n float64 from the standard input
    static double[] nextFloat64s(int n) {
        double[] slice = new double[n];
        for (int i = 0; i < n; i++) {
            slice[i] = nextFloat64();
        }
        return slice;
    }

    // Helper function to read a megabyte-sized string from the standard input
    static String nextMega() {
        StringBuilder buf = new StringBuilder();
        for (;;) {
            int l = 0, p = 0;
            try {
                l = rdr.read(buf, p, 1000000);
            } catch (Exception e) {
                e.printStackTrace();
            }
            p += l;
            if (l == -1) {
                break;
            }
        }
        return buf.toString();
    }

    // Helper function to print a formatted string to the standard output
    static void putf(String format, Object... a) {
        System.out.printf(format, a);
    }

    // Helper function to print a single line to the standard output
    static void puts(Object... a) {
        System.out.println(a);
    }

    
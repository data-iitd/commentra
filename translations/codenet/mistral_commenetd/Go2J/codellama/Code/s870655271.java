
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare and initialize variables
        int N, M, ans;

        // Read N and M from the standard input
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();

        // Check if N and M are equal to 1
        if (N == 1 && M == 1) {
            // If so, increment the ans variable
            ans += 1;
        } else if (1 < N && 1 < M) {
            // If N and M are greater than 1, calculate the area of the rectangle
            ans += (N - 2) * (M - 2);
        } else {
            // If N or M is equal to 1, calculate the number of points on the edge
            ans += (N * M) - 2;
        }

        // Print the value of ans to the standard output
        System.out.println(ans);
    }

    // Helper functions
    public static int max(int... x) {
        // Find the maximum value in the array x
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.max(x[i], res);
        }
        return res;
    }

    public static int min(int... x) {
        // Find the minimum value in the array x
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.min(x[i], res);
        }
        return res;
    }

    public static int pow(int x, int y) {
        // Calculate x raised to the power of y
        return (int) Math.pow(x, y);
    }

    public static int abs(int x) {
        // Calculate the absolute value of x
        return Math.abs(x);
    }

    public static int floor(int x) {
        // Round x down to the nearest integer
        return (int) Math.floor(x);
    }

    // Helper type and function for sorting a slice of integers based on their absolute values
    public static class SortBy implements Comparable<SortBy> {
        private int[] array;

        public SortBy(int[] array) {
            this.array = array;
        }

        @Override
        public int compareTo(SortBy other) {
            return abs(array[0]) - abs(other.array[0]);
        }
    }
}


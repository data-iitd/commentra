package main;

import java.io.*;
import java.util.*;

public class Main {

    // Reads the next integer from the input
    public static int nextInt() {
        return nextInt(); // Comment: Reads the next integer from the input
    }

    // Reads a slice of integers of length N
    public static int[] nextInts(int N) {
        return nextInts(N); // Comment: Reads a slice of integers of length N
    }

    // Main function to solve the problem
    public static void main(String[] args) {
        // Reads the number of steps N
        int N = nextInt(); // Comment: Reads the number of steps N
        
        // Reads the list of heights h
        int[] h = nextInts(N); // Comment: Reads the list of heights h
        
        // Initializes the DP array with zeros
        int[] dp = new int[N]; // Comment: Initializes the DP array with zeros
        for (int i = 0; i < N; i++) {
            dp[i] = 0;
        }
        
        // Sets the cost to reach the second step
        dp[1] = Math.abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
        
        // Computes the minimum cost to reach each step using dynamic programming
        for (int i = 2; i < N; i++) {
            dp[i] = Math.min(dp[i - 1] + Math.abs(h[i] - h[i - 1]),
                             dp[i - 2] + Math.abs(h[i] - h[i - 2]));
        }
        
        // Prints the minimum cost to reach the last step
        System.out.println(dp[N-1]); // Comment: Prints the minimum cost to reach the last step
    }

    // Utility function to find the absolute value of an integer
    public static int Abs(int a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }

    // Utility function to find the maximum value in a slice of integers
    public static int Max(int[] a) {
        int r = a[0];
        for (int i = 0; i < a.length; i++) {
            if (r < a[i]) {
                r = a[i];
            }
        }
        return r;
    }

    // Utility function to find the minimum value in a slice of integers
    public static int Min(int[] a) {
        int r = a[0];
        for (int i = 0; i < a.length; i++) {
            if (r > a[i]) {
                r = a[i];
            }
        }
        return r;
    }

    // Utility function to calculate the sum of a slice of integers
    public static int Sum(int[] a) {
        int r = 0;
        for (int i = 0; i < a.length; i++) {
            r += a[i];
        }
        return r;
    }

    // Pair struct to represent a pair of integers
    public static class Pair {
        int a, b;
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    // Pairs slice to represent a slice of Pair
    public static class Pairs extends ArrayList<Pair> {
        public Pairs() {
            super();
        }
        public Pairs(int n) {
            super(n);
        }
    }

}


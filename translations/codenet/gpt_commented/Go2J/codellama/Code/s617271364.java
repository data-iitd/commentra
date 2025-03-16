
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // Initialize scanner for input and writer for output
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder wtr = new StringBuilder();

    // Declare global variables
    static int N, ss, ans, A, B, C;

    public static void main(String[] args) throws IOException {
        // Read input values and split them into a string array
        String[] X = sc.readLine().split(" ");

        // Parse the first four values from the input
        N = Integer.parseInt(X[0]); // Number of elements
        A = Integer.parseInt(X[1]); // Target value A
        B = Integer.parseInt(X[2]); // Target value B
        C = Integer.parseInt(X[3]); // Target value C

        // Initialize arrays for dynamic programming and results
        int[] arr = new int[N]; // Array to hold input values
        int[] dp = new int[N]; // DP array to store current state
        ans = 10000; // Initialize answer with a large value
        ss = A + B + C; // Sum of target values

        // Read N integers from input and populate the array
        for (int i = 0; i < N; i++) {
            String[] Y = sc.readLine().split(" ");
            arr[i] = Integer.parseInt(Y[0]); // Store the integer in the array
        }

        // Perform depth-first search to find the optimal distribution
        dfs(dp, 0, arr);

        // Output the final answer
        System.out.println(ans);
    }

    // Recursive function to explore all distributions of items
    static void dfs(int[] dp, int times, int[] arr) {
        // Base case: if all items have been considered
        if (times >= N) {
            ans = Math.min(ans, calc(dp, arr)); // Calculate cost and update answer
            return;
        }

        // Explore all possible distributions (0 to 3)
        for (int i = 0; i < 4; i++) {
            dp[times] = i; // Assign current item to one of the four groups
            dfs(dp, times + 1, arr); // Recur for the next item
        }
    }

    // Calculate the cost of the current distribution
    static int calc(int[] dp, int[] arr) {
        int cost = 0, AA = 0, BB = 0, CC = 0; // Initialize cost and group sums

        // Count items in each group and calculate their sums
        int[] memo = new int[4];
        for (int i = 0; i < dp.length; i++) {
            memo[dp[i]]++; // Count items in each group
            if (dp[i] == 1) {
                AA += arr[i]; // Sum for group A
            } else if (dp[i] == 2) {
                BB += arr[i]; // Sum for group B
            } else if (dp[i] == 3) {
                CC += arr[i]; // Sum for group C
            }
        }

        // Calculate the cost based on the differences from target values
        cost += Math.abs(A - AA) + Math.abs(B - BB) + Math.abs(C - CC);

        // Penalize for missing groups and excess items
        for (int i = 1; i < 4; i++) {
            int a = memo[i];
            if (a < 1) {
                cost += 10000; // High penalty for missing group
            } else {
                cost += (a - 1) * 10; // Penalty for excess items
            }
        }

        return cost; // Return the calculated cost
    }

    // Helper function to read the next line of input
    static String nextLine() throws IOException {
        return sc.readLine();
    }

    // Helper function to find the minimum of two integers
    static int min(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    // Helper function to find the absolute value of an integer
    static int abs(int a) {
        if (a < 0) {
            return a * -1;
        }
        return a;
    }

    // Additional utility functions and types can be defined below
}


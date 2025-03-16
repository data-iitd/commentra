package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Initialize scanner for input and writer for output
		Scanner sc = new Scanner(System.in);
		BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));

		// Declare global variables
		int N, ss, ans, A, B, C;

		// Read input values and split them into a slice of strings
		String[] X = sc.nextLine().split(" ");

		// Parse the first four values from the input
		N = Integer.parseInt(X[0]); // Number of elements
		A = Integer.parseInt(X[1]); // Target value A
		B = Integer.parseInt(X[2]); // Target value B
		C = Integer.parseInt(X[3]); // Target value C

		// Initialize arrays for dynamic programming and results
		int[] arr = new int[N]; // Array to hold input values
		int[] dp = new int[N];  // DP array to store current state
		ans = 10000;           // Initialize answer with a large value
		ss = A + B + C;        // Sum of target values

		// Read N integers from input and populate the array
		for (int i = 0; i < N; i++) {
			String[] Y = sc.nextLine().split(" ");
			arr[i] = Integer.parseInt(Y[0]);
		}

		// Perform depth-first search to find the optimal distribution
		dfs(dp, 0, arr);

		// Output the final answer
		wtr.write(Integer.toString(ans) + "\n");

		// Flush the writer to ensure all output is written
		wtr.flush();
	}

	// Recursive function to explore all distributions of items
	public static void dfs(int[] dp, int times, int[] arr) {
		// Base case: if all items have been considered
		if (times >= N) {
			ans = Math.min(ans, calc(dp, arr)); // Calculate cost and update answer
			return;
		}

		// Explore all possible distributions (0 to 3)
		for (int i = 0; i < 4; i++) {
			dp[times] = i; // Assign current item to one of the four groups
			dfs(dp, times+1, arr); // Recur for the next item
		}
	}

	// Calculate the cost of the current distribution
	public static int calc(int[] dp, int[] arr) {
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
}


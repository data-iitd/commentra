package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Read the input values for N, A, B, and C
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();

		// Initialize the array to store the values and a dp array for choices
		int[] arr = new int[N];
		int[] dp = new int[N];
		int ans = 10000;
		int ss = A + B + C;

		// Read the array values from input
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
		}

		// Start the depth-first search to find the minimum cost
		dfs(dp, 0, arr);

		// Print the minimum cost found
		System.out.println(ans);
	}

	// Depth-first search function to explore different combinations of choices
	public static void dfs(int[] dp, int times, int[] arr) {
		if (times >= N) {
			ans = Math.min(ans, calc(dp, arr));
			return;
		}

		for (int i = 0; i < 4; i++) {
			dp[times] = i;
			dfs(dp, times+1, arr);
		}
	}

	// Function to calculate the cost based on the chosen combinations
	public static int calc(int[] dp, int[] arr) {
		int cost = 0, AA = 0, BB = 0, CC = 0;

		// Create a memoization array to count the occurrences of each choice
		int[] memo = new int[4];
		for (int i = 0; i < dp.length; i++) {
			memo[dp[i]]++;
			if (dp[i] == 1) {
				AA += arr[i];
			} else if (dp[i] == 2) {
				BB += arr[i];
			} else if (dp[i] == 3) {
				CC += arr[i];
			}
		}
		cost += Math.abs(A-AA) + Math.abs(B-BB) + Math.abs(C-CC);

		// Add additional cost for each choice that appears more than once
		for (int i = 1; i < 4; i++) {
			int a = memo[i];
			if (a < 1) {
				cost += 10000;
			} else {
				cost += (a - 1) * 10;
			}
		}

		return cost;
	}
}



// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

// main function is the entry point of the program
public class s114239323{
	public static void main(String[] args) {
		// Read the number of test cases N from standard input
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();

		// Read an array h of N integers from standard input
		int[] h = new int[N];
		for (int i = 0; i < N; i++) {
			h[i] = scanner.nextInt();
		}

		// Initialize a dp array of size N with zeros
		int[] dp = new int[N];
		for (int i = 0; i < N; i++) {
			dp[i] = 0;
		}

		// Set the first element of dp to the absolute difference between the first and second elements of h
		dp[1] = Math.abs(h[0] - h[1]);

		// Iterate over the array h from the second element to the last
		for (int i = 2; i < N; i++) {
			// Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
			dp[i] = Math.min(dp[i - 1] + Math.abs(h[i] - h[i - 1]), dp[i - 2] + Math.abs(h[i] - h[i - 2]));
		}

		// Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
		System.out.println(dp[N - 1]);
	}
}

// Helper functions to calculate the maximum, minimum, sum, and absolute difference of integers
public class s114239323{
	public static int max(int[] a) {
		int r = a[0];
		for (int i = 0; i < a.length; i++) {
			if (r < a[i]) {
				r = a[i];
			}
		}
		return r;
	}

	public static int min(int[] a) {
		int r = a[0];
		for (int i = 0; i < a.length; i++) {
			if (r > a[i]) {
				r = a[i];
			}
		}
		return r;
	}

	public static int sum(int[] a) {
		int r = 0;
		for (int i = 0; i < a.length; i++) {
			r += a[i];
		}
		return r;
	}

	public static int abs(int a) {
		if (a < 0) {
			return -a;
		}
		return a;
	}
}

// Helper function to read input from standard input as a single string
public class s114239323{
	public static String nextString() {
		return nextReader();
	}

	public static int nextInt() {
		return Integer.parseInt(nextReader());
	}

	public static int[] nextInts(int n) {
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		return r;
	}
}

// Helper function to read a single string from standard input
public class s114239323{
	public static String nextReader() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return "";
	}
}


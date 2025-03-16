// Package main is the entry point of the program

import (
	"bufio" // For reading input from standard input
	"fmt"   // For printing output
	"os"    // For reading input from files and writing output to files
	"strconv" // For converting strings to integers and back
)

// main function is the entry point of the program
public class Main {
	// Read the number of test cases N from standard input
	public static int nextInt() {
		return Integer.parseInt(nextReader());
	}

	// Read a single string from standard input
	public static String nextString() {
		return nextReader();
	}

	// Read a single integer from standard input
	public static int[] nextInts(int n) {
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		return r;
	}

	// Helper function to read input from standard input as a single string
	public static String nextReader() {
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return "";
	}

	// Helper function to read a single string from standard input
	public static String nextReader() {
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return "";
	}

	// Helper function to read a single integer from standard input
	public static int nextInt() {
		try {
			return Integer.parseInt(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
		return 0;
	}

	// Helper function to read an array of N integers from standard input
	public static int[] nextInts(int n) {
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		return r;
	}

	// Helper functions to calculate the maximum, minimum, sum, and absolute difference of integers
	public static int Max(int[] a) {
		int r = a[0];
		for (int i = 0; i < a.length; i++) {
			if (r < a[i]) {
				r = a[i];
			}
		}
		return r;
	}

	public static int Min(int[] a) {
		int r = a[0];
		for (int i = 0; i < a.length; i++) {
			if (r > a[i]) {
				r = a[i];
			}
		}
		return r;
	}

	public static int Sum(int[] a) {
		int r = 0;
		for (int i = 0; i < a.length; i++) {
			r += a[i];
		}
		return r;
	}

	public static int Abs(int a) {
		if (a < 0) {
			return -a;
		}
		return a;
	}

	// main function is the entry point of the program
	public static void main(String[] args) {
		// Read the number of test cases N from standard input
		int N = nextInt();

		// Read an array h of N integers from standard input
		int[] h = nextInts(N);

		// Initialize a dp array of size N with zeros
		int[] dp = new int[N];
		for (int i = 0; i < N; i++) {
			dp[i] = 0;
		}

		// Set the first element of dp to the absolute difference between the first and second elements of h
		dp[1] = Abs(h[0] - h[1]);

		// Iterate over the array h from the second element to the last
		for (int i = 2; i < N; i++) {
			// Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
			dp[i] = Min(new int[]{dp[i - 1] + Abs(h[i] - h[i - 1]), dp[i - 2] + Abs(h[i] - h[i - 2])});
		}

		// Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
		System.out.println(dp[N - 1]);
	}
}


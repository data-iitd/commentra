package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		// Read the number of elements in the first array A and initialize it
		int A = nextInt();
		// Read the number of elements in the second array B
		int B = nextInt();
		// Read the number of queries Q
		int Q = nextInt();

		// Initialize the first array with boundary values
		int[] s = new int[A+2];
		s[0], s[A+1] = -1000000000, 1000000000;
		// Populate the first array with input values
		for (int i = 1; i <= A; i++) {
			s[i] = nextInt();
		}

		// Initialize the second array with boundary values
		int[] t = new int[B+2];
		t[0], t[B+1] = -1000000000, 1000000000;
		// Populate the second array with input values
		for (int i = 1; i <= B; i++) {
			t[i] = nextInt();
		}

		// Process each query
		for (int i = 0; i < Q; i++) {
			// Read the query value x
			int x = nextInt();
			// Find the position in the first array where x would fit
			int b = Arrays.binarySearch(s, x);
			if (b < 0) {
				b = -b - 1;
			}
			// Find the position in the second array where x would fit
			int d = Arrays.binarySearch(t, x);
			if (d < 0) {
				d = -d - 1;
			}
			// Initialize the result with infinity
			int res = 1000000000;

			// Check the closest values in the first array
			for (int S : new int[]{s[b-1], s[b]}) {
				// Check the closest values in the second array
				for (int T : new int[]{t[d-1], t[d]}) {
					// Calculate the distances for both possible paths
					int d1 = Math.abs(S-x) + Math.abs(T-S);
					int d2 = Math.abs(T-x) + Math.abs(S-T);
					// Update the result with the minimum distance found
					res = Math.min(res, Math.min(d1, d2));
				}
			}

			// Output the result for the current query
			System.out.println(res);
		}
	}

	// Input handling. ----------

	// Initialize the scanner for reading input
	static Scanner sc = new Scanner(System.in);

	// Function to read the next integer from input
	static int nextInt() {
		return sc.nextInt();
	}

	// Function to read the next float from input
	static double nextFloat() {
		return sc.nextDouble();
	}

	// Function to read the next string from input
	static String nextString() {
		return sc.next();
	}

	// ---------- Input handling.

	// Utility functions. ----------

	// Function to calculate the absolute value
	static int abs(int x) {
		return Math.abs(x);
	}

	// Function to find the minimum of two integers
	static int min(int x, int y) {
		return Math.min(x, y);
	}

	// Function to find the maximum of two integers
	static int max(int x, int y) {
		return Math.max(x, y);
	}

	// ---------- Utility functions.
}


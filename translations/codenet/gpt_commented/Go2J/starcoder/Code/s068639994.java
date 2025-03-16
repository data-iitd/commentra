package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Read the number of elements
		int n = getInt();
		// Read the integer slice from input
		int[] ls = getIntSlice(n);
		// Create a reversed copy of the original slice
		int[] lsRev = Arrays.copyOf(ls, n);
		// Sort the original slice in ascending order
		Arrays.sort(ls);
		// Sort the reversed slice in descending order
		Arrays.sort(lsRev);

		// Initialize the answer variable
		int ans = 0;
		// Iterate through all pairs of elements in the sorted slice
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				// Determine the minimum and maximum of the two selected elements
				int p = Math.min(ls[i], ls[j]);
				int q = Math.max(ls[i], ls[j]);
				// Calculate the differences and sums needed for searching
				int x = q - p;
				int y = q + p;

				// Find the left boundary for elements greater than x
				int l = Arrays.binarySearch(ls, x);
				// Find the right boundary for elements less than y
				int r = n - Arrays.binarySearch(lsRev, y);

				// Calculate the number of valid elements in the range
				int sum = r - l;
				// Adjust the count if the current indices are within the range
				if (i >= l) && (i <= r) {
					sum--;
				}
				if (j >= l) && (j <= r) {
					sum--;
				}
				// Ensure the sum is non-negative
				sum = Math.max(0, sum);
				// Accumulate the result
				ans += sum;
			}
		}

		// Divide the final answer by 3 as per the problem requirements
		ans /= 3;
		// Output the result
		puts(ans);
	}

	// min returns the smaller of two integers
	public static int min(int a, int b) {
		return Math.min(a, b);
	}

	// max returns the larger of two integers
	public static int max(int a, int b) {
		return Math.max(a, b);
	}

	// -----------------------------------------

	// Global variables for input and output handling
	private static final Scanner scanner = new Scanner(System.in);
	private static final PrintWriter writer = new PrintWriter(System.out);

	// main is the entry point of the program
	public static void main(String[] args) throws IOException {
		// Set the scanner to split input into words
		scanner.useDelimiter("\\s+");
		// Call the main function to execute the logic
		mainFn();
		// Flush the buffered output
		writer.close();
	}

	// getInt reads an integer from input
	public static int getInt() {
		return Integer.parseInt(scanner.next());
	}

	// getIntSlice reads a slice of integers from input
	public static int[] getIntSlice(int n) {
		int[] is = new int[n];
		for (int i = 0; i < n; i++) {
			is[i] = getInt();
		}
		return is;
	}

	// getString reads a string from input
	public static String getString() {
		return scanner.next();
	}

	// puts writes the given arguments to the output
	public static void puts(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
}


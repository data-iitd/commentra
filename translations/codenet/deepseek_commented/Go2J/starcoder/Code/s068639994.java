package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Get the number of elements in the slice.
		int n = getInt();
		// Get the slice of integers.
		int[] ls = getIntSlice(n);
		// Create a reversed version of the slice.
		int[] lsRev = new int[n];
		System.arraycopy(ls, 0, lsRev, 0, n);
		// Sort the original slice in ascending order.
		Arrays.sort(ls);
		// Sort the reversed slice in descending order.
		Arrays.sort(lsRev);

		// Initialize the answer variable.
		int ans = 0;
		// Loop through the slice to calculate the answer.
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				// Calculate p and q based on the current elements.
				int p = Math.min(ls[i], ls[j]);
				int q = Math.max(ls[i], ls[j]);
				// Calculate x and y based on p and q.
				int x = q - p;
				int y = q + p;

				// Find the left boundary using binary search.
				int l = Arrays.binarySearch(ls, x);
				// Find the right boundary using binary search.
				int r = n - Arrays.binarySearch(lsRev, y);

				// Calculate the sum of valid pairs.
				int sum = r - l;
				// Adjust the sum if the current indices are within the range.
				if (i >= l) && (i <= r) {
					sum--;
				}
				if (j >= l) && (j <= r) {
					sum--;
				}
				// Ensure the sum is not negative.
				sum = Math.max(0, sum);
				// Add the sum to the answer.
				ans += sum;
			}
		}

		// Divide the answer by 3 to get the final result.
		ans /= 3;
		// Print the final answer.
		puts(ans);
	}

	// Helper functions to find the minimum and maximum of two integers.
	public static int min(int a, int b) {
		return Math.min(a, b);
	}

	public static int max(int a, int b) {
		return Math.max(a, b);
	}

	// -----------------------------------------

	// Global variables for input/output operations.
	private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	private static final BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	// Helper functions to read/write integers.
	private static String next() throws IOException {
		while (reader.ready() && reader.peek() =='') {
			reader.read();
		}
		String str = "";
		if (reader.ready()) {
			str = reader.readLine();
		}
		return str;
	}

	private static int getInt() throws IOException {
		return Integer.parseInt(next());
	}

	private static int[] getIntSlice(int n) throws IOException {
		int[] arr = new int[n];
		String[] strs = next().split(" ");
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(strs[i]);
		}
		return arr;
	}

	private static void puts(int[] arr) throws IOException {
		for (int i = 0; i < arr.length; i++) {
			if (i!= 0) {
				writer.write(" ");
			}
			writer.write(arr[i]);
		}
		writer.write("\n");
	}

	private static void puts(int i) throws IOException {
		writer.write(i + "\n");
	}

	private static void puts(String str) throws IOException {
		writer.write(str);
		writer.write("\n");
	}

	// -----------------------------------------

	// Main function to initialize the program.
	public static void main(String[] args) throws IOException {
		// Get the number of elements in the slice.
		int n = getInt();
		// Get the slice of integers.
		int[] ls = getIntSlice(n);
		// Create a reversed version of the slice.
		int[] lsRev = new int[n];
		System.arraycopy(ls, 0, lsRev, 0, n);
		// Sort the original slice in ascending order.
		Arrays.sort(ls);
		// Sort the reversed slice in descending order.
		Arrays.sort(lsRev);

		// Initialize the answer variable.
		int ans = 0;
		// Loop through the slice to calculate the answer.
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				// Calculate p and q based on the current elements.
				int p = Math.min(ls[i], ls[j]);
				int q = Math.max(ls[i], ls[j]);
				// Calculate x and y based on p and q.
				int x = q - p;
				int y = q + p;

				// Find the left boundary using binary search.
				int l = Arrays.binarySearch(ls, x);
				// Find the right boundary using binary search.
				int r = n - Arrays.binarySearch(lsRev, y);

				// Calculate the sum of valid pairs.
				int sum = r - l;
				// Adjust the sum if the current indices are within the range.
				if (i >= l) && (i <= r) {
					sum--;
				}
				if (j >= l) && (j <= r) {
					sum--;
				}
				// Ensure the sum is not negative.
				sum = Math.max(0, sum);
				// Add the sum to the answer.
				ans += sum;
			}
		}

		// Divide the answer by 3 to get the final result.
		ans /= 3;
		// Print the final answer.
		puts(ans);
	}
}


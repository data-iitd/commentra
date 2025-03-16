
// Package main is the entry point of the program
package main

// Import the required packages
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

// mainFn is the main function of the program
public class main {
	// Define the main function
	public static void main(String[] args) {
		// Get the number of elements in the input array
		int n = getInt();
		// Get the input array
		int[] ls = getIntSlice(n);
		// Create a reversed copy of the input array
		int[] lsRev = new int[n];
		// Copy the input array to the reversed copy
		System.arraycopy(ls, 0, lsRev, 0, n);
		// Sort the input array in ascending order
		Arrays.sort(ls);
		// Sort the reversed copy of the array in descending order
		Collections.sort(Arrays.asList(lsRev), Collections.reverseOrder());

		// Initialize the answer variable
		int ans = 0;
		// Iterate through all pairs of elements in the array
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				// Find the minimum and maximum elements of the current pair
				int p = Math.min(ls[i], ls[j]);
				int q = Math.max(ls[i], ls[j]);
				// Calculate the difference between the maximum and minimum elements
				int x = q - p;
				int y = q + p;
				// Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
				int l = Arrays.binarySearch(ls, x);
				int r = n - Collections.binarySearch(Arrays.asList(lsRev), y);
				// Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
				int sum = r - l;
				// Check if the current pair lies within the range [l, r]
				if (i >= l && i <= r) {
					sum--;
				}
				if (j >= l && j <= r) {
					sum--;
				}
				// Ensure that the sum is not negative
				sum = Math.max(0, sum);
				// Add the sum to the answer variable
				ans += sum;
			}
		}
		// Divide the answer by 3 and print it
		ans /= 3;
		puts(ans);
	}

	// getInt reads an integer from the standard input
	public static int getInt() {
		Scanner scanner = new Scanner(System.in);
		// Convert the input string to an integer and return it
		int i = scanner.nextInt();
		return i;
	}

	// getIntSlice reads an array of integers from the standard input
	public static int[] getIntSlice(int n) {
		// Allocate memory for the array
		int[] is = new int[n];
		// Read each element of the array from the standard input
		for (int i = 0; i < n; i++) {
			is[i] = getInt();
		}
		// Return the array
		return is;
	}

	// puts writes the given arguments to the standard output, followed by a newline character
	public static void puts(int a) {
		// Write the arguments to the writer buffer
		System.out.println(a);
	}
}


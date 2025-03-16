package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize a new scanner to read input from standard input
		Scanner sc = new Scanner(System.in);
		
		// Set the modulus value to 1000000007
		int mod = 1000000007;
		
		// Set the scanner to split input by whitespace
		sc.useDelimiter("\\s");
		
		// Read the number of elements
		int n = sc.nextInt();
		
		// Initialize a slice to hold the integers
		int[] as = new int[n];
		
		// Read n integers from input
		for (int i = 0; i < n; i++) {
			as[i] = sc.nextInt();
		}
		
		// Initialize a slice to hold the unique sorted integers
		int[] xs = new int[1];
		xs[0] = as[0];
		
		// Iterate through the input integers starting from the second element
		for (int j = 1; j < n; j++) {
			// Use binary search to find the position to insert the current integer
			int idx = sort(xs, as[j]);
			
			// If the index is equal to the length of xs, append the integer
			if (idx == xs.length) {
				int[] tmp = new int[xs.length + 1];
				System.arraycopy(xs, 0, tmp, 0, xs.length);
				tmp[xs.length] = as[j];
				xs = tmp;
			} else {
				// Otherwise, replace the existing integer at the found index
				xs[idx] = as[j];
			}
		}
		
		// Print the number of unique integers found
		System.out.println(xs.length);
	}
	
	// Sort the given slice using binary search
	public static int sort(int[] xs, int x) {
		// Use binary search to find the position to insert the current integer
		int idx = sort(xs, 0, xs.length - 1, x);
		
		// If the index is equal to the length of xs, append the integer
		if (idx == xs.length) {
			int[] tmp = new int[xs.length + 1];
			System.arraycopy(xs, 0, tmp, 0, xs.length);
			tmp[xs.length] = x;
			xs = tmp;
		} else {
			// Otherwise, replace the existing integer at the found index
			xs[idx] = x;
		}
		
		return idx;
	}
	
	// Sort the given slice using binary search
	public static int sort(int[] xs, int lo, int hi, int x) {
		// If the slice is empty, return the index to insert the current integer
		if (lo == hi) {
			return lo;
		}
		
		// Find the midpoint of the slice
		int mid = (lo + hi) / 2;
		
		// If the midpoint is less than the current integer, search the right half
		if (xs[mid] < x) {
			return sort(xs, mid + 1, hi, x);
		}
		
		// If the midpoint is greater than the current integer, search the left half
		if (xs[mid] > x) {
			return sort(xs, lo, mid - 1, x);
		}
		
		// Otherwise, the midpoint is equal to the current integer, return the midpoint
		return mid;
	}
}


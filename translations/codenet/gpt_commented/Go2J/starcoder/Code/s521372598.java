package main;

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		// Read the number of elements
		int n = getInt();
		// Read the integer slice of size n
		int[] as = getIntSlice(n);

		// Create a new slice to store adjusted values
		int[] xs = new int[n];
		for (int i = 0; i < n; i++) {
			// Adjust each element by subtracting its index and adding 1
			xs[i] = as[i] - i + 1;
		}
		// Sort the adjusted values
		Arrays.sort(xs);

		// Find the median value from the sorted slice
		int b = xs[n / 2];
		int ans = 0;
		// Calculate the total distance from each element to the median
		for (int x : xs) {
			ans += Math.abs(x - b);
		}
		// Output the result
		System.out.println(ans);
	}

	// abs function returns the absolute value of an integer
	public static int abs(int n) {
		if (n < 0) {
			return -n;
		}
		return n;
	}

	// -----------------------------------------

	public static final int inf = (int) 1e9; // A constant representing infinity
	// public static final int mod = (int) 1e9 + 7; // Uncomment if modular arithmetic is needed

	// Scanner for reading input
	static Scanner sc = new Scanner(System.in);
	// Writer for output
	static BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

	// getInt reads an integer from input
	public static int getInt() throws IOException {
		return Integer.parseInt(sc.next());
	}

	// getIntSlice reads a slice of integers from input
	public static int[] getIntSlice(int n) throws IOException {
		int[] ret = new int[n];
		for (int i = 0; i < n; i++) {
			ret[i] = getInt(); // Read each integer
		}
		return ret;
	}

	// getString reads a string from input
	public static String getString() throws IOException {
		return sc.next();
	}

	// getRunes converts a string to a slice of runes
	public static char[] getRunes() throws IOException {
		return getString().toCharArray();
	}
}


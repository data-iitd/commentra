// Importing necessary packages
package main;

import java.io.*;
import java.util.*;

// Constants and variables declaration

// Function to read input from standard input using buffered reader
class reader {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	// Function to read input from standard input using buffered reader
	static String next() throws IOException {
		while (st == null ||!st.hasMoreElements())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	// Function to read input from standard input using buffered reader
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	// Function to read input from standard input using buffered reader
	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	// Function to read input from standard input using buffered reader
	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
}

// Main function
public class Main {
	// Function to read input from standard input using buffered reader
	public static void main(String[] args) throws IOException {
		// Creating a new scanner object
		reader sc = new reader();

		// Reading input
		int n = sc.nextInt();
		int x = sc.nextInt();

		// Initializing arrays
		int[] a = new int[n];
		int[] v = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			v[i] = a[i];
		}

		// Initializing answer variable
		int ans = Integer.MAX_VALUE;

		// Iterating through all possible subarrays
		for (int k = 0; k < n; k++) {
			// Initializing variable to store sum of subarray elements
			int kans = 0;

			// Iterating through all elements of the subarray
			for (int i = 0; i < n; i++) {
				// Checking if current index is out of bounds for subarray
				if (i - k < 0) {
					// Updating current element in subarray with minimum of itself and corresponding element from the main array
					v[i] = Math.min(v[i], a[n + i - k]);
				} else {
					// Updating current element in subarray with minimum of itself and previous element in subarray
					v[i] = Math.min(v[i], a[i - k]);
				}

				// Adding current element to the sum of subarray
				kans += v[i];
			}

			// Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
			ans = Math.min(ans, kans + k * x);
		}

		// Printing the answer
		System.out.println(ans);
	}
}

// -------------------------------
// Function to check if a given number is inside a given range
public boolean in(int c, int a, int z) {
	return c >= a && c < z;
}

// Function to convert boolean value to integer
public int btoi(boolean b) {
	if (b) {
		return 1;
	}
	return 0;
}

// Function to convert integer value to boolean
public boolean itob(int a) {
	if (a == 0) {
		return false;
	}
	return true;
}


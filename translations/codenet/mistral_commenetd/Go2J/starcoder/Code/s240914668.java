// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

public class Main {
	// Declare a scanner to read input from stdin
	static Scanner sc = new Scanner(System.in);

	// Declare a writer to write output to stdout
	static BufferedWriter wt = new BufferedWriter(new OutputStreamWriter(System.out));

	// Declare a function to read a single word from stdin
	static String next() throws IOException {
		return sc.next();
	}

	// Declare a function to read a single integer from stdin
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	// Declare a function to read a single float from stdin
	static float nextFloat() throws IOException {
		return Float.parseFloat(next());
	}

	// Declare a function to read n integers from stdin
	static int[] nextInts(int n) throws IOException {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}

	// Declare a function to read n floats from stdin
	static float[] nextFloats(int n) throws IOException {
		float[] arr = new float[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextFloat();
		}
		return arr;
	}

	// Declare a function to read a megabyte-sized string from stdin
	static String nextMega() throws IOException {
		return sc.useDelimiter("\\A").next();
	}

	// Declare a function to print a formatted string to stdout
	static void putf(String format, Object... a) throws IOException {
		wt.write(String.format(format, a));
	}

	// Declare a function to print a single line to stdout
	static void puts(Object... a) throws IOException {
		for (Object o : a) {
			wt.write(o.toString());
			wt.write(" ");
		}
		wt.write("\n");
	}

	public static void main(String[] args) throws IOException {
		// Read the number of integers
		int n = nextInt();

		// Read the array of integers
		int[] a = nextInts(n);

		// Initialize the answer variable
		int ans = 0;

		// Iterate through the array 'a'
		for (int i = 0; i < n; i++) {
			// Initialize left and right indices
			int l = i, r = i + 1;

			// Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
			while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
				r++;
			}

			// Increment the answer variable
			ans++;

			// Update the index 'i' to 'r' for the next iteration
			i = r;
		}

		// Print the answer
		puts(ans);
		wt.flush();
	}
}


package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Set the scanner to split input by whitespace
		sc.useDelimiter("\\s+");

		// Read the number of integers
		int n = nextInt();
		// Read the integers into a slice
		int[] a = nextInts(n);

		// Initialize the answer counter
		int ans = 0;

		// Iterate through the slice of integers
		for (int i = 0; i < n; i++) {
			// Set the left and right pointers for the current segment
			int l = i, r = i + 1;

			// Expand the right pointer while the conditions are met
			while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
				r++;
			}

			// Increment the answer for each segment found
			ans++;
			// Move the left pointer to the end of the current segment
			i = r;
		}

		// Output the final count of segments
		putf("%d\\n", ans);
		// Flush the buffered writer to ensure all output is written
		wt.flush();
	}

	static Scanner sc = new Scanner(System.in);
	static BufferedWriter wt = new BufferedWriter(new OutputStreamWriter(System.out));

	// Function to read the next string from input
	static String next() throws IOException {
		return sc.next();
	}

	// Function to read the next integer from input
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	// Function to read the next float64 from input
	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	// Function to read a slice of integers from input
	static int[] nextInts(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		return a;
	}

	// Function to read a slice of float64 from input
	static double[] nextDoubles(int n) throws IOException {
		double[] a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextDouble();
		}
		return a;
	}

	// Function to read a large block of text from input
	static String nextMega() throws IOException {
		char[] buf = new char[1000000];
		int idx = 0;
		while (true) {
			int c = rdr.read();
			if (c == -1) {
				break;
			}
			buf[idx++] = (char) c;
		}
		return new String(buf, 0, idx);
	}

	// Function to format and write output to the buffered writer
	static void putf(String format, Object... a) throws IOException {
		wt.write(String.format(format, a));
	}

	// Function to write a line of output to the buffered writer
	static void puts(Object... a) throws IOException {
		wt.write(Arrays.deepToString(a).replaceAll("],", "],\n"));
	}
}


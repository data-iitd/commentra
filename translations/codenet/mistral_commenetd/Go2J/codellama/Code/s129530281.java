
// Package main is the entry point of the program
package main

import java.io.BufferedReader; // Import BufferedReader for reading lines
import java.io.InputStreamReader; // Import InputStreamReader for reading from standard input
import java.io.PrintWriter; // Import PrintWriter for formatted output
import java.io.IOException; // Import IOException for handling input/output errors
import java.util.StringTokenizer; // Import StringTokenizer for tokenizing strings

// getScanner function returns a BufferedReader instance configured for reading words
public static BufferedReader getScanner(InputStreamReader fp) {
	return new BufferedReader(fp);
}

// getNextString function returns the next word as a string
public static String getNextString(BufferedReader scanner) throws IOException {
	return scanner.readLine();
}

// getNextInt function returns the next integer from the scanner
public static int getNextInt(BufferedReader scanner) throws IOException {
	return Integer.parseInt(getNextString(scanner));
}

// getNextInt64 function returns the next 64-bit integer from the scanner
public static long getNextInt64(BufferedReader scanner) throws IOException {
	return Long.parseLong(getNextString(scanner));
}

// getNextUint64 function returns the next 64-bit unsigned integer from the scanner
public static long getNextUint64(BufferedReader scanner) throws IOException {
	return Long.parseUnsignedLong(getNextString(scanner));
}

// getNextFloat64 function returns the next 64-bit floating-point number from the scanner
public static double getNextFloat64(BufferedReader scanner) throws IOException {
	return Double.parseDouble(getNextString(scanner));
}

// main function is the entry point of the program
public static void main(String[] args) throws IOException {
	// Open the standard input file if a command-line argument is provided
	InputStreamReader fp = new InputStreamReader(System.in);
	if (args.length > 0) {
		fp = new InputStreamReader(new FileInputStream(args[0]));
	}

	// Initialize a PrintWriter for formatted output
	PrintWriter writer = new PrintWriter(System.out);

	// Read the first two integers from the input
	int n = getNextInt(getScanner(fp));
	int m = getNextInt(getScanner(fp));

	// Initialize the Segment struct with the given size n
	Segment seg = new Segment();
	seg.init(n);

	// Process the input data by maximizing the segments
	for (int i = 0; i < n; i++) {
		seg.maximize(i, getNextInt(getScanner(fp)));
	}
	for (int i = 0; i < m; i++) {
		seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1);
	}

	// Calculate the answer and print it to the output
	long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += seg.bucket[0][i];
	}

	// Print the answer to the output
	writer.println(ans);

	// Flush the writer buffer to ensure all data is written
	writer.flush();
}

// Segment type represents a segment tree data structure
class Segment {
	int n, h, i, chunk;
	int[] unit;
	int[][] bucket;

	// init function initializes the Segment struct with the given size n
	public void init(int n) {
		this.n = n;
		this.unit = new int[1];
		this.unit[0] = 1;
		this.bucket = new int[1][n];

		// Calculate the chunk size for the segment tree
		chunk = 8;
		for (int i = 0; n > 1; i++) {
			n = (n-1)/chunk + 1;
			bucket = Arrays.copyOf(bucket, bucket.length+1);
			bucket[bucket.length-1] = new int[n];
			unit = Arrays.copyOf(unit, unit.length+1);
			unit[unit.length-1] = unit[i]*chunk;
		}
		h = unit.length;
	}

	// maximize function updates the segment tree with the given index and value
	public void maximize(int index, int value) {
		// Update the leaf node with the given index and value
		bucket[0][index] = value;

		// Propagate the update to the parent nodes
		for (i = 0; i < h-1; i++) {
			int s = index - index%chunk;
			int t = s + chunk;
			if (t > bucket[i].length) {
				t = bucket[i].length;
			}
			int parent = index / chunk;
			int max = 0;
			for (int i = s; i < t; i++) {
				if (max < bucket[i]) {
					max = bucket[i];
				}
			}
			bucket[i+1][parent] = max;
			index /= chunk;
		}
	}

	// top function returns the index of the maximum value in the current segment
	public int top() {
		int index = 0;
		for (i = h - 2; i >= 0; i--) {
			int s = index * chunk;
			int t = s + chunk;
			if (t > bucket[i].length) {
				t = bucket[i].length;
			}
			for (int i = s; i < t; i++) {
				if (bucket[i] == bucket[i+1][index]) {
					index = i;
					break;
				}
			}
		}

		return index;
	}
}



// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

// getScanner function returns a BufferedReader instance configured for reading words
BufferedReader getScanner(String file) throws Exception {
	if (file == null) {
		return new BufferedReader(new InputStreamReader(System.in));
	} else {
		return new BufferedReader(new FileReader(file));
	}
}

// getNextString function returns the next word as a string
String getNextString(BufferedReader br) throws Exception {
	return br.readLine();
}

// getNextInt function returns the next integer from the scanner
int getNextInt(BufferedReader br) throws Exception {
	return Integer.parseInt(getNextString(br));
}

// getNextInt64 function returns the next 64-bit integer from the scanner
long getNextInt64(BufferedReader br) throws Exception {
	return Long.parseLong(getNextString(br));
}

// getNextFloat64 function returns the next 64-bit floating-point number from the scanner
double getNextFloat64(BufferedReader br) throws Exception {
	return Double.parseDouble(getNextString(br));
}

// main function is the entry point of the program
public class s129530281{
	public static void main(String[] args) throws Exception {
		// Open the standard input file if a command-line argument is provided
		BufferedReader br = getScanner(args.length > 0? args[0] : null);

		// Initialize a PrintWriter for formatted output
		PrintWriter writer = new PrintWriter(System.out);

		// Read the first two integers from the input
		int n = getNextInt(br);
		int m = getNextInt(br);

		// Initialize the Segment struct with the given size n
		Segment seg = new Segment();
		seg.init(n);

		// Process the input data by maximizing the segments
		for (int i = 0; i < n; i++) {
			seg.maximize(i, getNextInt(br));
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

		// Close the writer and flush the output
		writer.close();
	}
}

// Segment type represents a segment tree data structure
class Segment {
	int n, h, i, chunk;
	int[] unit;
	int[][] bucket;

	// init function initializes the Segment struct with the given size n
	void init(int n) {
		this.n = n;
		unit = new int[1];
		unit[0] = 1;
		bucket = new int[1][n];

		// Calculate the chunk size for the segment tree
		chunk = 8;
		for (int i = 0; n > 1; i++) {
			n = (n-1)/chunk + 1;
			bucket = Arrays.copyOf(bucket, i+2);
			bucket[i+1] = new int[n];
			unit = Arrays.copyOf(unit, i+2);
			unit[i+1] = unit[i]*chunk;
		}
		h = unit.length;
	}

	// maximize function updates the segment tree with the given index and value
	void maximize(int index, int value) {
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
			for (int j = s; j < t; j++) {
				if (max < bucket[i][j]) {
					max = bucket[i][j];
				}
			}
			bucket[i+1][parent] = max;
			index /= chunk;
		}
	}

	// top function returns the index of the maximum value in the current segment
	int top() {
		int index = 0;
		for (i = h - 2; i >= 0; i--) {
			int s = index * chunk;
			int t = s + chunk;
			if (t > bucket[i].length) {
				t = bucket[i].length;
			}
			for (int j = s; j < t; j++) {
				if (bucket[i][j] == bucket[i+1][index]) {
					index = j;
					break;
				}
			}
		}

		return index;
	}
}

// Translate the above Java code to C++ and end with comment "
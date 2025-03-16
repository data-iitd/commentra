// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

// getScanner function returns a new instance of bufio.Scanner
func getScanner(fp *File) *Scanner {
	return new Scanner(fp);
}

// getNextString function reads the next token from the input
func getNextString(scanner *Scanner) string {
	scanner.useDelimiter(" ");
	return scanner.next();
}

// getNextInt function reads the next integer from the input
func getNextInt(scanner *Scanner) int {
	scanner.useDelimiter(" ");
	return scanner.nextInt();
}

// getNextInt64 function reads the next 64-bit integer from the input
func getNextInt64(scanner *Scanner) int64 {
	scanner.useDelimiter(" ");
	return scanner.nextLong();
}

// getNextUint64 function reads the next 64-bit unsigned integer from the input
func getNextUint64(scanner *Scanner) uint64 {
	scanner.useDelimiter(" ");
	return scanner.nextLong();
}

// getNextFloat64 function reads the next 64-bit floating-point number from the input
func getNextFloat64(scanner *Scanner) float64 {
	scanner.useDelimiter(" ");
	return scanner.nextDouble();
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
			this.bucket = Arrays.copyOf(this.bucket, this.bucket.length+1);
			this.bucket[this.bucket.length-1] = new int[n];
			this.unit = Arrays.copyOf(this.unit, this.unit.length+1);
			this.unit[this.unit.length-1] = this.unit[i]*chunk;
		}
		this.h = this.unit.length;
		this.chunk = chunk;
	}

	// maximize function updates the segment tree with the given index and value
	public void maximize(int index, int value) {
		// Update the leaf node with the given index and value
		this.bucket[0][index] = value;

		// Propagate the update to the parent nodes
		for (this.i = 0; this.i < this.h-1; this.i++) {
			int s = index - index%this.chunk;
			int t = s + this.chunk;
			if (t > this.bucket[this.i].length) {
				t = this.bucket[this.i].length;
			}
			int parent = index / this.chunk;
			int max = 0;
			for (int i = s; i < t; i++) {
				if (max < this.bucket[this.i][i]) {
					max = this.bucket[this.i][i];
				}
			}
			this.bucket[this.i+1][parent] = max;
			index /= this.chunk;
		}
	}

	// top function returns the index of the maximum value in the current segment
	public int top() {
		int index = 0;
		for (this.i = this.h - 2; this.i >= 0; this.i--) {
			int s = index * this.chunk;
			int t = s + this.chunk;
			if (t > this.bucket[this.i].length) {
				t = this.bucket[this.i].length;
			}
			for (int i = s; i < t; i++) {
				if (this.bucket[this.i][i] == this.bucket[this.i+1][index]) {
					index = i;
					break;
				}
			}
		}

		return index;
	}
}

// main function is the entry point of the program
public class Main {
	public static void main(String[] args) {
		// Read the first two integers from the input
		Scanner scanner = getScanner(System.in);
		int n = getNextInt(scanner);
		int m = getNextInt(scanner);

		// Initialize the Segment struct with the given size n
		Segment seg = new Segment();
		seg.init(n);

		// Process the input data by maximizing the segments
		for (int i = 0; i < n; i++) {
			seg.maximize(i, getNextInt(scanner));
		}
		for (int i = 0; i < m; i++) {
			seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1);
		}

		// Calculate the answer and print it to the output
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += seg.bucket[0][i];
		}

		// Print the answer to the output
		System.out.println(ans);
	}
}


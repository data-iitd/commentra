
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

// getScanner initializes a new scanner that reads from the given file pointer.
public static BufferedReader getScanner(InputStreamReader fp) {
	return new BufferedReader(fp);
}

// getNextString reads the next word from the scanner.
public static String getNextString(BufferedReader scanner) throws IOException {
	return scanner.readLine();
}

// getNextInt converts the next word to an integer.
public static int getNextInt(BufferedReader scanner) throws IOException {
	return Integer.parseInt(getNextString(scanner));
}

// getNextInt64 converts the next word to a 64-bit integer.
public static long getNextInt64(BufferedReader scanner) throws IOException {
	return Long.parseLong(getNextString(scanner));
}

// getNextUint64 converts the next word to an unsigned 64-bit integer.
public static long getNextUint64(BufferedReader scanner) throws IOException {
	return Long.parseUnsignedLong(getNextString(scanner));
}

// getNextFloat64 converts the next word to a floating-point number.
public static double getNextFloat64(BufferedReader scanner) throws IOException {
	return Double.parseDouble(getNextString(scanner));
}

// Main function handles file input, initializes a segment tree, and processes the input to compute an answer.
public static void main(String[] args) throws IOException {
	InputStreamReader fp = new InputStreamReader(System.in);
	BufferedReader scanner = getScanner(fp);
	StringBuilder writer = new StringBuilder();

	// Read the number of elements (n) and the number of operations (m).
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Initialize the segment tree.
	Segment seg = new Segment();
	seg.init(n);

	// Populate the segment tree with initial values.
	for (int i = 0; i < n; i++) {
		seg.maximize(i, getNextInt(scanner));
	}

	// Perform the specified number of operations on the segment tree.
	for (int i = 0; i < m; i++) {
		seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1);
	}

	// Calculate the sum of the values in the root bucket of the segment tree.
	long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += seg.bucket[0][i];
	}

	// Write the result to the standard output.
	writer.append(ans + "\n");
	System.out.print(writer);
}

// Segment struct represents a segment tree and includes methods to initialize it and update/query it.
class Segment {
	int n, h, i, chunk;
	int[] unit;
	int[][] bucket;

	// init initializes the segment tree with a given size n.
	public void init(int n) {
		this.n = n;
		this.unit = new int[1];
		this.unit[0] = 1;
		this.bucket = new int[1][n];

		int chunk = 8;
		for (int i = 0; n > 1; i++) {
			n = (n-1)/chunk + 1;
			this.bucket = Arrays.copyOf(this.bucket, this.bucket.length + 1);
			this.bucket[this.bucket.length - 1] = new int[n];
			this.unit = Arrays.copyOf(this.unit, this.unit.length + 1);
			this.unit[this.unit.length - 1] = this.unit[i]*chunk;
		}
		this.h = this.unit.length;
		this.chunk = chunk;
	}

	// maximize updates the value at a given index in the segment tree.
	public void maximize(int index, int value) {
		this.bucket[0][index] = value;
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

	// top returns the index of the maximum value in the segment tree.
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


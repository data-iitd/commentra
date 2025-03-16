package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

		// Read the number of elements (n) and the number of operations (m).
		int n = scanner.nextInt();
		int m = scanner.nextInt();

		// Initialize the segment tree.
		Segment seg = new Segment();
		seg.init(n);

		// Populate the segment tree with initial values.
		for (int i = 0; i < n; i++) {
			seg.maximize(i, scanner.nextInt());
		}

		// Perform the specified number of operations on the segment tree.
		for (int i = 0; i < m; i++) {
			seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1);
		}

		// Calculate the sum of the values in the root bucket of the segment tree.
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += seg.bucket[0][i];
		}

		// Write the result to the standard output.
		writer.write(ans + "\n");
		writer.close();
	}
}

class Segment {
	int n, h, i, chunk;
	int[] unit;
	int[][] bucket;

	public void init(int n) {
		this.n = n;
		this.unit = new int[1];
		this.unit[0] = 1;
		this.bucket = new int[1][n];

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

	public void maximize(int index, int value) {
		this.bucket[0][index] = value;
		for (this.i = 0; this.i < this.h-1; this.i++) {
			int s = index - index%chunk;
			int t = s + chunk;
			if (t > this.bucket[this.i].length) {
				t = this.bucket[this.i].length;
			}
			int parent = index / chunk;
			int max = 0;
			for (int i = s; i < t; i++) {
				if (max < this.bucket[this.i][i]) {
					max = this.bucket[this.i][i];
				}
			}
			this.bucket[this.i+1][parent] = max;
			index /= chunk;
		}
	}

	public int top() {
		int index = 0;
		for (this.i = this.h - 2; this.i >= 0; this.i--) {
			int s = index * chunk;
			int t = s + chunk;
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


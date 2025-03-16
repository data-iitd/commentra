package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Determine the input source: either standard input or a file specified as a command-line argument
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// Read the number of elements and operations
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());

		// Initialize the Segment structure
		Segment seg = new Segment();
		seg.init(n); // Initialize the segment with size n

		// Populate the segment with initial values
		for (int i = 0; i < n; i++) {
			seg.maximize(i, Integer.parseInt(br.readLine())); // Maximize the segment with the input values
		}

		// Perform m operations to maximize the segment
		for (int i = 0; i < m; i++) {
			seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1); // Maximize using the top value and half of the last bucket's first element
		}

		// Calculate the final answer by summing up the values in the first bucket
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += seg.bucket[0][i]; // Accumulate the values
		}

		// Output the final result
		bw.write(ans + "\n");
		bw.flush(); // Flush the buffered writer to ensure all output is written
		bw.close();
	}
}

class Segment {
	int n, h, i, chunk;
	int[] unit;
	int[][] bucket;

	// init initializes the segment structure with the given size n.
	public void init(int n) {
		this.n = n;
		this.unit = new int[1]; // Initialize unit array
		this.unit[0] = 1;
		this.bucket = new int[1][n]; // Initialize bucket array
		this.bucket[0] = new int[n];

		chunk = 8; // Define the chunk size
		for (int i = 0; n > 1; i++) {
			n = (n-1)/chunk + 1; // Reduce n based on the chunk size
			this.bucket = Arrays.copyOf(this.bucket, this.bucket.length+1); // Append a new bucket
			this.unit = Arrays.copyOf(this.unit, this.unit.length+1); // Update unit array
			this.unit[i+1] = this.unit[i]*chunk;
		}
		this.h = this.unit.length; // Set the height of the segment
		this.chunk = chunk; // Set the chunk size
	}

	// maximize updates the segment at a given index with a new value.
	public void maximize(int index, int value) {
		this.bucket[0][index] = value; // Set the value in the first bucket
		for (this.i = 0; this.i < this.h-1; this.i++) {
			int s = index - index%chunk; // Calculate the start of the current chunk
			int t = s + chunk; // Calculate the end of the current chunk
			if (t > this.bucket[this.i].length) {
				t = this.bucket[this.i].length; // Adjust end if it exceeds the bucket length
			}
			int parent = index / chunk; // Determine the parent index
			int max = 0; // Initialize max value
			for (int i = s; i < t; i++) {
				if (max < this.bucket[this.i][i]) {
					max = this.bucket[this.i][i]; // Find the maximum value in the current chunk
				}
			}
			this.bucket[this.i+1][parent] = max; // Update the parent bucket with the maximum value
			index /= chunk; // Move to the parent index for the next iteration
		}
	}

	// top retrieves the index of the top value in the segment.
	public int top() {
		int index = 0; // Start from the root index
		for (this.i = this.h - 2; this.i >= 0; this.i--) {
			int s = index * chunk; // Calculate the start of the current chunk
			int t = s + chunk; // Calculate the end of the current chunk
			if (t > this.bucket[this.i].length) {
				t = this.bucket[this.i].length; // Adjust end if it exceeds the bucket length
			}
			for (int i = s; i < t; i++) {
				if (this.bucket[this.i][i] == this.bucket[this.i+1][index]) {
					index = i; // Update index if the value matches the top value
					break;
				}
			}
		}

		return index; // Return the index of the top value
	}
}


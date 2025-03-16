package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		// Read the number of elements N and the threshold K
		int N = ReadInt();
		int K = ReadInt();

		// Read the two slices of integers As and Fs
		int[] As = ReadInts(N);
		int[] Fs = ReadInts(N);

		// Sort the As slice in ascending order
		Arrays.sort(As);
		// Sort the Fs slice in descending order
		Arrays.sort(Fs, Collections.reverseOrder());

		// Create a slice to hold the scores calculated from As and Fs
		int[] scores = new int[N];
		for (int i = 0; i < N; i++) {
			// Calculate the score for each pair of As and Fs
			scores[i] = As[i] * Fs[i];
		}

		// Sort the scores in descending order
		Arrays.sort(scores, Collections.reverseOrder());

		// Initialize binary search boundaries
		int ok = scores[0]; // The maximum possible score
		int ng = -1;        // The minimum possible score

		// Perform binary search to find the maximum score that can be achieved
		while (ok - ng > 1) {
			int mid = (ok + ng) / 2; // Calculate the midpoint of the current range

			boolean isOK = true; // Flag to check if the current mid is achievable
			int k = K;           // Remaining threshold to adjust scores
			for (int i = 0; isOK && i < N; i++) {
				// If the current score exceeds mid, calculate how much we need to reduce
				if (As[i] * Fs[i] > mid) {
					k -= As[i] - mid / Fs[i];
				}
				// If we exceed the allowed threshold, mark isOK as false
				if (k < 0) {
					isOK = false;
				}
			}

			// Adjust binary search boundaries based on whether mid is achievable
			if (isOK) {
				ok = mid; // If achievable, move the upper boundary
			} else {
				ng = mid; // If not achievable, move the lower boundary
			}
		}

		// Print the maximum achievable score
		System.out.println(ok);
	}

	// ReadInts reads n integers from input and returns them as a slice
	public static int[] ReadInts(int n) {
		int[] ret = new int[n];
		for (int i = 0; i < n; i++) {
			ret[i] = ReadInt(); // Read each integer and store it in the slice
		}
		return ret;
	}

	// Initialize a scanner for reading input
	static Scanner sc = new Scanner(System.in);

	// Read reads the next token from input as a string
	public static String Read() {
		return sc.next();
	}

	// ReadInt reads the next integer from input and returns it
	public static int ReadInt() {
		return Integer.parseInt(Read());
	}
}


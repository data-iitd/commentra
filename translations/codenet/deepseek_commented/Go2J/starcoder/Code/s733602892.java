package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		// Read the number of elements N and the maximum number of operations K
		int N = ReadInt();
		int K = ReadInt();
		
		// Read the list of integers As
		int[] As = ReadInts(N);
		
		// Read the list of integers Fs
		int[] Fs = ReadInts(N);
		
		// Sort As in ascending order
		Arrays.sort(As);
		
		// Sort Fs in descending order
		Arrays.sort(Fs);
		Arrays.sort(Fs, Collections.reverseOrder());
		
		// Create a list to store the scores
		int[] scores = new int[N];
		
		// Calculate the scores by multiplying corresponding elements of As and Fs
		for (int i = 0; i < N; i++) {
			scores[i] = As[i] * Fs[i];
		}
		
		// Sort the scores in descending order to prepare for binary search
		Arrays.sort(scores);
		Arrays.sort(scores, Collections.reverseOrder());
		
		// Initialize the boundaries for binary search
		int ok = scores[0];
		int ng = -1;
		
		// Perform binary search to find the maximum score
		while (ok - ng > 1) {
			int mid = (ok + ng) / 2;
			
			// Check if it's possible to achieve mid score with at most K operations
			boolean isOK = true;
			int k = K;
			for (int i = 0; isOK && i < N; i++) {
				if (As[i] * Fs[i] > mid) {
					k -= As[i] - mid / Fs[i];
				}
				if (k < 0) {
					isOK = false;
				}
			}
			
			// Adjust the search boundaries based on the result of the check
			if (isOK) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		
		// Print the maximum score found
		System.out.println(ok);
	}
	
	// ReadInts reads a list of integers from stdin
	public static int[] ReadInts(int n) {
		int[] ret = new int[n];
		for (int i = 0; i < n; i++) {
			ret[i] = ReadInt();
		}
		return ret;
	}
	
	// Initialize the scanner with buffer and word split function
	static {
		Scanner sc = new Scanner(System.in);
		sc.useDelimiter("[^\\p{L}]+");
	}
	
	// Read reads a single string from stdin
	public static String Read() {
		return sc.next();
	}
	
	// ReadInt reads a single integer from stdin
	public static int ReadInt() {
		return Integer.parseInt(sc.next());
	}
}


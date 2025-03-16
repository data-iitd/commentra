package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);

		// Read the number of elements (N), maximum count (C), and time limit (K)
		int N = sc.nextInt();
		int C = sc.nextInt();
		int K = sc.nextInt();

		// Read N time values from input
		int[] t = new int[N];
		for (int i = 0; i < N; i++) {
			t[i] = sc.nextInt();
		}

		// Sort the time values in ascending order
		Arrays.sort(t);

		// Initialize variables for counting groups and tracking the end time
		int ans = 1; // Start with one group
		int cnt = 1; // Count of elements in the current group
		int end = t[0] + K; // Calculate the end time for the first group

		// Iterate through the sorted time values
		for (int i = 1; i < N; i++) {
			// Check if we can add the current time to the current group
			if (cnt < C && t[i] <= end) {
				cnt++; // Increment the count of the current group
			} else {
				// Start a new group since the current time exceeds the end time
				cnt = 1; // Reset the count for the new group
				end = t[i] + K; // Update the end time for the new group
				ans++; // Increment the group count
			}
		}
		System.out.println(ans); // Output the total number of groups formed
	}
}


package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Read the values for R, G, B, and N from standard input
		Scanner sc = new Scanner(System.in);
		int R = sc.nextInt(); // Number of red items
		int G = sc.nextInt(); // Number of green items
		int B = sc.nextInt(); // Number of blue items
		int N = sc.nextInt(); // Total number of items to choose

		int ans = 0; // Variable to store the count of valid combinations

		// Iterate over possible counts of red items (x)
		for (int x = 0; x <= N; x++) {
			// Iterate over possible counts of green items (y)
			for (int y = 0; y <= N; y++) {
				// Calculate the remaining items after choosing x red and y green
				int tmp = N - R*x - G*y;
				// Check if the remaining items can be fully represented by blue items
				if (tmp >= 0 && tmp%B == 0) {
					ans++; // Increment the count of valid combinations
				}
			}
		}

		// Output the total count of valid combinations
		System.out.println(ans);
	}

}


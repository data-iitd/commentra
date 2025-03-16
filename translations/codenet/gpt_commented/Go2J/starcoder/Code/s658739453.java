package main;

import java.util.Scanner;

public class Main {

	// Define a constant for the modulo operation
	private static final int d = 1000000007;

	public static void main(String[] args) {
		// Declare variables for the number of elements (n) and the number of blocked positions (p)
		int n, p;

		// Read the total number of elements (n) and the number of blocked positions (p) from input
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		p = sc.nextInt();
		sc.close();

		// Create a map to store the blocked positions
		HashMap<Integer, Integer> mdans = new HashMap<Integer, Integer>();

		// Read the blocked positions and store them in the map
		for (int index = 0; index < p; index++) {
			int n1;
			Scanner sc = new Scanner(System.in);
			n1 = sc.nextInt();
			mdans.put(n1, n1);
			sc.close();
		}

		// Initialize a slice to store the number of ways to reach each position
		int[] dp = new int[n + 1];

		// Base cases: There is 1 way to reach the 0th and 1st positions
		dp[0] = 1;
		dp[1] = 1;

		// If the first position is blocked, set the number of ways to reach it to 0
		if (mdans.containsKey(1)) {
			dp[1] = 0;
		}

		// Iterate through positions from 2 to n to calculate the number of ways to reach each position
		for (int i = 2; i <= n; i++) {
			// If the current position is blocked, skip the calculation
			if (mdans.containsKey(i)) {
				continue;
			}
			// Calculate the number of ways to reach the current position using the previous two positions
			dp[i] = (dp[i - 1] + dp[i - 2]) % d;
		}

		// Print the number of ways to reach the nth position
		System.out.println(dp[n]);
	}
}


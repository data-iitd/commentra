package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Set the input source to standard input; if a file is provided as an argument, open that file.
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		if (args.length > 0) {
			br = new BufferedReader(new FileReader(args[0]));
		}

		// Create a new scanner to read from the input source and configure it to split input into words.
		Scanner scanner = new Scanner(br);

		// Read the first two integers, n and m, from the input.
		int n = scanner.nextInt();
		int m = scanner.nextInt();

		// Initialize a map to store the positions that are blocked (not allowed).
		Map<Integer, Integer> aa = new HashMap<Integer, Integer>();
		for (int i = 0; i < m; i++) {
			// Read each blocked position and mark it in the map.
			aa.put(scanner.nextInt(), 1);
		}

		// Create a dynamic programming array to store the number of ways to reach each position.
		int[] dp = new int[n+1];
		dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

		// Iterate through each position from 0 to n.
		for (int i = 0; i < n; i++) {
			// Check the next two positions (i+1 and i+2) to see if they can be reached.
			for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
				if (aa.containsKey(i+ii)) {
					continue; // If blocked, skip to the next iteration.
				}
				// Update the number of ways to reach position i+ii based on the current position i.
				dp[i+ii] += dp[i];
				dp[i+ii] %= 1000000007; // Ensure the result stays within the modulo limit.
			}
		}

		// Output the total number of ways to reach position n.
		System.out.println(dp[n]);
	}
}


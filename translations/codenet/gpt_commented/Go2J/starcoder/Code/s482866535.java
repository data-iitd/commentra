package main;

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		// Determine the input source: standard input or a file specified as a command-line argument.
		InputStreamReader isr = null;
		if (args.length > 0) {
			isr = new FileReader(args[0]);
		} else {
			isr = new InputStreamReader(System.in);
		}

		// Initialize the scanner for reading input and a writer for output.
		Scanner scanner = new Scanner(isr);
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

		// Read the number of elements.
		int n = scanner.nextInt();
		int[] mm = new int[n+1]; // Create a slice to hold the input values.
		int[][] dp = new int[n+1][n+1]; // Create a 2D slice for dynamic programming.

		// Initialize the 2D slice for dynamic programming.
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = 0; // Each entry is initialized to zero by default.
			}
		}

		// Read the input values into the mm slice.
		for (int i = 0; i < n; i++) {
			mm[i] = scanner.nextInt(); // Read the first value.
			mm[i+1] = scanner.nextInt(); // Read the second value.
		}

		// Perform dynamic programming to calculate the minimum cost.
		for (int l = 2; l <= n; l++) { // l is the length of the subproblem.
			for (int i = 1; i <= n-l+1; i++) { // i is the starting index of the subproblem.
				int j = i + l - 1; // j is the ending index of the subproblem.
				for (int k = i; k <= j-1; k++) { // k is the partition point.
					// Calculate the cost of multiplying the matrices.
					int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
					// Update the dp table with the minimum cost found.
					if (dp[i][j] == 0 || dp[i][j] > d) {
						dp[i][j] = d;
					}
				}
			}
		}

		// Output the minimum cost of multiplying the entire sequence of matrices.
		writer.write(Integer.toString(dp[1][n]));
		writer.newLine();

		// Flush the writer to ensure all output is written.
		writer.flush();
	}
}


package main;

import java.io.*;
import java.util.*;

public class Main {

	// Function to read the next word from the scanner
	public static String getNextWord(Scanner scanner) {
		scanner.useDelimiter("\\s");
		String word = scanner.next();
		scanner.useDelimiter("\\n");
		return word;
	}

	// Function to read the next integer from the scanner
	public static int getNextInt(Scanner scanner) {
		return Integer.parseInt(getNextWord(scanner));
	}

	// Main function
	public static void main(String[] args) {
		// Open the standard input file if the command line argument is provided
		InputStreamReader isr = null;
		if (args.length > 0) {
			try {
				isr = new InputStreamReader(new FileInputStream(args[0]));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		} else {
			isr = new InputStreamReader(System.in);
		}
		BufferedReader reader = new BufferedReader(isr);
		Scanner scanner = new Scanner(reader);

		// Read the first two integers from the input
		int n = getNextInt(scanner);
		int m = getNextInt(scanner);

		// Initialize an associative array to store the elements
		Map<Integer, Integer> aa = new HashMap<Integer, Integer>();
		// Read m elements and store them in the associative array
		for (int i = 0; i < m; i++) {
			aa.put(getNextInt(scanner), 1);
		}

		// Initialize a slice of length n+1 for dynamic programming
		int[] dp = new int[n+1];
		// Initialize the first element of the slice
		dp[0] = 1;

		// Iterate through the array from index 0 to n-1
		for (int i = 0; i < n; i++) {
			// Iterate through the prefix sum from i to i+2
			for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
				// Skip if the current index and its sum are already present in the associative array
				if (aa.containsKey(i+ii)) {
					continue;
				}
				// Calculate the dynamic programming value for the current index
				dp[i+ii] += dp[i];
				// Perform modulo operation to keep the value within the range of 10^9+7
				dp[i+ii] %= 1000000007;
			}
		}

		// Print the final answer
		System.out.println(dp[n]);

		// Close the scanner
		scanner.close();
	}

}


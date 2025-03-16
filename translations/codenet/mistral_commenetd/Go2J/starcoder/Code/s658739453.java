
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Read the first integer 'n' from the standard input
		int n = sc.nextInt();

		// Read the second integer 'p' from the standard input
		int p = sc.nextInt();

		// Initialize a map'mdans' for storing distinct numbers
		Map<Integer, Integer> mdans = new HashMap<Integer, Integer>();

		// Read 'p' distinct numbers from the standard input and store them in the map'mdans'
		for (int index = 0; index < p; index++) {
			int n1 = sc.nextInt();
			mdans.put(n1, n1); // Store the number 'n1' in the map'mdans' with its own key
		}

		// Initialize an array 'dp' of size 'n+1' with a default value of '0'
		int[] dp = new int[n + 1];
		dp[0] = 1; // Initialize the first element of the array 'dp' with a value of '1'
		dp[1] = 1; // Initialize the second element of the array 'dp' with a value of '1'

		// Initialize the third element of the array 'dp' with a value of '0' if the number '1' is present in the map'mdans'
		if (mdans.containsKey(1)) {
			dp[1] = 0;
		}

		// Calculate the remaining elements of the array 'dp' using the previous elements
		for (int i = 2; i <= n; i++) {
			if (mdans.containsKey(i)) {
				continue; // Skip the current iteration if the number 'i' is present in the map'mdans'
			}
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007; // Calculate the current element of the array 'dp' as the sum of the previous two elements modulo 'd'
		}

		// Print the final result
		System.out.println(dp[n]); // Print the value of the last element of the array 'dp'
	}
}


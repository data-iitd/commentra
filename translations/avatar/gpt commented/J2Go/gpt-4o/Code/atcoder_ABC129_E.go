package main

import (
	"fmt"
)

func main() {
	// Define a constant for the modulo operation
	const M = 1000000007

	// Read a line of input
	var s string
	fmt.Scanln(&s)

	// Get the length of the input string
	n := len(s)

	// Initialize a 2D slice for dynamic programming
	// dp[i][0] will store the count of valid sequences ending with '0'
	// dp[i][1] will store the count of valid sequences ending with '1'
	dp := make([][2]int, n+1)

	// Base case: There is one way to have an empty sequence
	dp[0][0] = 1

	// Iterate through each character in the input string
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			// Carry forward the counts for sequences ending with '0' and '1'
			dp[i+1][0] = dp[i][0]
			dp[i+1][1] = dp[i][1]
			// Count sequences ending with '1' that can be formed by doubling the previous count
			dp[i+1][1] = (dp[i][1] * 2) % M
		} else {
			// If the current character is '1', calculate new counts
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % M
			// Count sequences ending with '0' that can be formed by doubling the previous count
			dp[i+1][0] = (dp[i][0] * 2) % M
			// Count sequences ending with '1' that can be formed by doubling the previous count
			dp[i+1][1] = (dp[i+1][1] + (dp[i][1] * 2) % M) % M
		}
	}

	// Output the total number of valid sequences
	fmt.Println((dp[n][0] + dp[n][1]) % M)
}

// <END-OF-CODE>

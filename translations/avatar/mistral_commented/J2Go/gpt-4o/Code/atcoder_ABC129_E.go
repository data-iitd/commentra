package main

import (
	"fmt"
)

func main() {
	// Initialize modulus constant M
	const M = 1000000007

	// Read the input string
	var s string
	fmt.Scanln(&s)

	// Get the length of the string
	n := len(s)

	// Initialize a 2D slice dp of size (n+1) x 2 to store the prefix sums
	dp := make([][2]int, n+1)

	// Initialize the first cell of dp with 1 in both rows
	dp[0][0] = 1
	dp[0][1] = 0

	// Iterate through the character array from index 0 to n-1
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			// If the current character is '0', then both rows of dp[i+1] are copied from dp[i]
			dp[i+1][0] = dp[i][0]
			dp[i+1][1] = dp[i][1]
		} else {
			// If the current character is '1', then the first row of dp[i+1] is updated
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % M
		}

		if s[i] == '0' {
			// If the current character is '0', update the second row of dp[i+1]
			dp[i+1][1] = (dp[i+1][1] + (dp[i][1]*2)%M) % M
		} else {
			// If the current character is '1', update both rows of dp[i+1]
			dp[i+1][0] = (dp[i+1][0] + (dp[i][0]*2)%M) % M
			dp[i+1][1] = (dp[i+1][1] + (dp[i][1]*2)%M) % M
		}
	}

	// Print the final result which is the sum of dp[n][0] and dp[n][1] modulo M
	fmt.Println((dp[n][0] + dp[n][1]) % M)
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	const M = 1000000007 // Defining a constant for modulo operation
	var s string
	fmt.Scanln(&s) // Reading the input string
	n := len(s)    // Getting the length of the input string
	dp := make([][2]int, n+1) // Initializing the dynamic programming table
	dp[0][0] = 1 // Setting the base case for dp[0][0]

	// Iterating through each character of the input string
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			dp[i+1][0] = dp[i][0] // Copying the previous state for '0'
			dp[i+1][1] = dp[i][1] // Copying the previous state for '0'
		} else {
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % M // Updating dp[i+1][1] for '1'
		}

		// Additional updates for '0' and '1'
		if s[i] == '0' {
			dp[i+1][1] = (dp[i+1][1] + (dp[i][1]*2)%M) % M // Updating dp[i+1][1] for '0'
		} else {
			dp[i+1][0] = (dp[i+1][0] + (dp[i][0]*2)%M) % M // Updating dp[i+1][0] for '1'
			dp[i+1][1] = (dp[i+1][1] + (dp[i][1]*2)%M) % M // Updating dp[i+1][1] for '1'
		}
	}

	// Printing the result as the sum of dp[n][0] and dp[n][1] modulo M
	fmt.Println((dp[n][0] + dp[n][1]) % M)
}

// <END-OF-CODE>

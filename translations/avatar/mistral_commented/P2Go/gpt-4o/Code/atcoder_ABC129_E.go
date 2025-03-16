package main

import (
	"fmt"
)

const mod = 1000000007

func main() {
	var l string
	fmt.Scan(&l)
	n := len(l)

	// Initialize 2D dynamic programming table
	dp := make([][2]int, n+1)

	// Base case: empty string has 1 solution
	dp[0][0] = 1

	// Iterate through each character in the input string
	for i, c := range l {
		if c == '0' {
			dp[i+1][0] = (dp[i][0] + dp[i+1][0]) % mod
			dp[i+1][1] = (dp[i][1]*3 + dp[i+1][1]) % mod
		} else {
			dp[i+1][0] = (dp[i][0]*2 + dp[i+1][0]) % mod
			dp[i+1][1] = (dp[i][0] + dp[i][1]*3 + dp[i+1][1]) % mod
		}
	}

	// Calculate the final answer
	result := (dp[n][0] + dp[n][1]) % mod
	fmt.Println(result)
}

// <END-OF-CODE>

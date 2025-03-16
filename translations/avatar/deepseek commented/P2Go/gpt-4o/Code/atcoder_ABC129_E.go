package main

import (
	"fmt"
)

func main() {
	const mod = 10e9 + 7 // Set the modulus to a large prime number
	var l string
	fmt.Scan(&l) // Read the input string
	n := len(l)  // Calculate the length of the input string

	// Initialize the dynamic programming table
	dp := make([][2]int, n+1)
	dp[0][0] = 1 // Base case: one empty sequence

	// Iterate over each character in the input string
	for i, c := range l {
		if c == '0' {
			dp[i+1][0] = (dp[i][0] + dp[i+1][0]) % mod // Add sequences ending with zero
			dp[i+1][1] = (dp[i][1]*3 + dp[i+1][1]) % mod // Triple sequences ending with one
		} else {
			dp[i+1][0] = (dp[i][0]*2 + dp[i+1][0]) % mod // Double sequences ending with zero
			dp[i+1][1] = (dp[i][0] + dp[i+1][1]) % mod // Add sequences ending with zero
			dp[i+1][1] = (dp[i][1]*3 + dp[i+1][1]) % mod // Triple sequences ending with one
		}
	}

	// Calculate and print the final result
	result := (dp[n][0] + dp[n][1]) % mod
	fmt.Println(result)
}

// <END-OF-CODE>

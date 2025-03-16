package main

import "fmt"

func main() {
	// Read the input string
	var l string
	fmt.Scanf("%s", &l)

	// Calculate the length of the input string
	n := len(l)

	// Initialize the dynamic programming table
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}
	dp[0][0] = 1 // Base case: one empty sequence

	// Iterate over each character in the input string
	for i, c := range l {
		if c == '0' {
			dp[i+1][0] += dp[i][0] // Add sequences ending with zero
			dp[i+1][1] += dp[i][1] * 3 // Triple sequences ending with one
		} else {
			dp[i+1][0] += dp[i][0] * 2 // Double sequences ending with zero
			dp[i+1][1] += dp[i][0] // Add sequences ending with zero
			dp[i+1][1] += dp[i][1] * 3 // Triple sequences ending with one
		}

		// Take modulo to prevent overflow
		dp[i+1][0] %= 1000000007
		dp[i+1][1] %= 1000000007
	}

	// Calculate and print the final result
	result := (dp[n][0] + dp[n][1]) % 1000000007
	fmt.Println(result)
}


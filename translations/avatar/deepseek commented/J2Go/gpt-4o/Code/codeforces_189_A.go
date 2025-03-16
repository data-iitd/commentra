package main

import (
	"fmt"
)

func main() {
	// Initialize a scanner to read input from the user
	var n, a, b, c int
	fmt.Scan(&n, &a, &b, &c)

	// Store the coin values in a slice
	arr := []int{a, b, c}

	// Initialize a dp slice with all elements set to a very small value
	maxn := 4010
	dp := make([]int, maxn)
	for i := 0; i < n; i++ {
		dp[i] = -1 << 31 // Equivalent to Integer.MIN_VALUE in Java
	}

	// Set the base case where dp[0] is 0
	dp[0] = 0

	// Iterate over the coin values and update the dp slice
	for _, coin := range arr {
		for j := coin; j < len(dp); j++ {
			if dp[j-coin] != -1<<31 { // Check if dp[j-coin] is not the minimum value
				dp[j] = max(dp[j], dp[j-coin]+1)
			}
		}
	}

	// Print the value of dp[n]
	fmt.Println(dp[n])
}

// Helper function to get the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

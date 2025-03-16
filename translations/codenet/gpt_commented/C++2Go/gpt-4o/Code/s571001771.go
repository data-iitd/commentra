package main

import (
	"fmt"
	"math"
)

const INF = 123456789012

func main() {
	var n, m int64
	fmt.Scan(&n, &m)

	// Arrays to store the keys and costs
	key := make([]int64, m+1)
	cost := make([]int64, m+1)

	// DP table to store the minimum costs for each state
	dp := make([][]int64, 1<<12+5)
	for i := range dp {
		dp[i] = make([]int64, 1005)
		for j := range dp[i] {
			dp[i][j] = INF // Set each entry to infinity
		}
	}

	// Base case: cost of obtaining no keys is 0
	dp[0][0] = 0

	// Read the costs and keys for each item
	for i := int64(1); i <= m; i++ {
		var b int64
		fmt.Scan(&cost[i], &b) // Read cost and number of keys for item i
		for j := int64(0); j < b; j++ {
			var c int64
			fmt.Scan(&c) // Read each key
			key[i] += (1 << (c - 1)) // Update the key bitmask for item i
		}
	}

	// Fill the DP table
	for i := int64(0); i < (1 << n); i++ {
		for j := int64(0); j < m; j++ {
			// Update the DP table for not taking the (j+1)th item
			dp[i][j+1] = min(dp[i][j], dp[i][j+1])
			// Update the DP table for taking the (j+1)th item
			dp[i|key[j+1]][j+1] = min(dp[i|key[j+1]][j+1], dp[i][j]+cost[j+1])
		}
	}

	// Check if it's possible to obtain all keys
	if dp[(1<<n)-1][m] == INF {
		fmt.Println(-1) // If not possible, print -1
	} else {
		fmt.Println(dp[(1<<n)-1][m]) // Print the minimum cost to obtain all keys
	}
}

// Helper function to find the minimum of two int64 values
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>

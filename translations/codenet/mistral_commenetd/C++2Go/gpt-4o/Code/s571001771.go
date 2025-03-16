package main

import (
	"fmt"
	"math"
)

const INF = 123456789012 // Constants and data types are defined here

func main() {
	var n, m int64 // n is the number of switches, m is the number of bulbs
	fmt.Scan(&n, &m)

	// Initialize arrays
	key := make([]int64, m+1)
	cost := make([]int64, m+1)
	dp := make([][]int64, 1<<12+5)
	for i := range dp {
		dp[i] = make([]int64, 1005)
		for j := range dp[i] {
			dp[i][j] = INF // Set all values to infinite
		}
	}
	dp[0][0] = 0 // Set the initial value of dp[0][0] to 0

	// Read bulbs' information
	for i := int64(1); i <= m; i++ {
		var b int64 // The number of switches needed to turn on this bulb
		fmt.Scan(&cost[i], &b)

		// Update key array
		for j := int64(0); j < b; j++ {
			var c int64 // The position of the switch
			fmt.Scan(&c)
			key[i] += (1 << (c - 1)) // Set the corresponding bit in key[i] to 1
		}
	}

	// Fill dynamic programming table
	for i := int64(0); i < (1 << n); i++ { // Iterate through all possible combinations of switches
		for j := int64(0); j < m; j++ { // Iterate through all bulbs
			dp[i][j+1] = min(dp[i][j], dp[i][j+1]) // Update dp[i][j+1] with the minimum value
			dp[i|key[j+1]][j+1] = min(dp[i|key[j+1]][j+1], dp[i][j]+cost[j+1]) // Update dp[i|key[j+1]][j+1]
		}
	}

	// Output result
	if dp[(1<<n)-1][m] == INF {
		fmt.Println(-1) // Check if the minimum cost is infinite
	} else {
		fmt.Println(dp[(1<<n)-1][m]) // Output the minimum cost
	}
}

// Helper function to find minimum of two int64 values
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

package main

import (
	"fmt"
	"math"
)

const INF = 123456789012

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read the number of keys (n) and items (m)

	// Initialize the dp array with infinity
	dp := make([][]int64, 1<<12+5)
	for i := range dp {
		dp[i] = make([]int64, 1005)
		for j := range dp[i] {
			dp[i][j] = INF
		}
	}
	dp[0][0] = 0 // Base case: no keys and no cost

	cost := make([]int64, 1005) // Array to store the cost of each item
	key := make([]int64, 1005)  // Array to store the keys in a binary format

	for i := 1; i <= m; i++ { // Read the cost and keys for each item
		var b int
		fmt.Scan(&cost[i], &b)
		for j := 0; j < b; j++ {
			var c int
			fmt.Scan(&c)
			key[i] += 1 << (c - 1) // Convert key information into binary format
		}
	}

	for i := 0; i < (1 << n); i++ { // Iterate through all possible states
		for j := 0; j < m; j++ {
			dp[i][j+1] = min(dp[i][j], dp[i][j+1]) // Update the dp array based on the current state
			dp[i|key[j+1]][j+1] = min(dp[i|key[j+1]][j+1], dp[i][j]+cost[j+1]) // Update the dp array based on the next state
		}
	}

	if dp[(1<<n)-1][m] == INF {
		fmt.Println(-1) // Check if it's not possible to collect all keys and output -1
	} else {
		fmt.Println(dp[(1<<n)-1][m]) // Output the minimum cost to collect all keys
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>

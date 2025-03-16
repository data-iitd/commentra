package main

import (
	"fmt"
	"math"
)

const INF = 123456789012

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize the DP table with infinity
	dp := make([][]int, 1<<12+5)
	for i := range dp {
		dp[i] = make([]int, 1005)
		for j := range dp[i] {
			dp[i][j] = INF // Set each entry to infinity
		}
	}

	// Base case: cost of obtaining no keys is 0
	dp[0][0] = 0

	// Arrays to store the keys and costs
	key := make([]int, 1005)
	cost := make([]int, 1005)

	// Read the costs and keys for each item
	for i := 1; i <= m; i++ {
		var b int
		fmt.Scan(&cost[i], &b) // Read cost and number of keys for item i
		for j := 0; j < b; j++ {
			var c int
			fmt.Scan(&c) // Read each key
			key[i] += 1 << (c - 1) // Update the key bitmask for item i
		}
	}

	// Fill the DP table
	for i := 0; i < (1 << n); i++ {
		for j := 0; j < m; j++ {
			// Update the DP table for not taking the (j+1)th item
			if dp[i][j] < dp[i][j+1] {
				dp[i][j+1] = dp[i][j]
			}
			// Update the DP table for taking the (j+1)th item
			if dp[i|key[j+1]][j+1] > dp[i][j]+cost[j+1] {
				dp[i|key[j+1]][j+1] = dp[i][j] + cost[j+1]
			}
		}
	}

	// Check if it's possible to obtain all keys
	if dp[(1<<n)-1][m] == INF {
		fmt.Println(-1) // If not possible, print -1
	} else {
		fmt.Println(dp[(1<<n)-1][m]) // Print the minimum cost to obtain all keys
	}
}


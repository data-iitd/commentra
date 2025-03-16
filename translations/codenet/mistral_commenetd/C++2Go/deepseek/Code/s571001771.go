package main

import (
	"fmt"
	"math"
)

const INF = 123456789012

var key [1005]int
var cost [1005]int
var dp [1<<12 + 5][1005]int

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize dynamic programming table with infinite values
	for i := 0; i < (1 << 12 + 5); i++ {
		for j := 0; j < 1005; j++ {
			dp[i][j] = INF
		}
	}
	dp[0][0] = 0

	// Read bulbs' information
	for i := 1; i <= m; i++ {
		var b int
		fmt.Scan(&cost[i], &b)

		// Update key array
		for j := 0; j < b; j++ {
			var c int
			fmt.Scan(&c)
			key[i] |= 1 << (c - 1)
		}
	}

	// Fill dynamic programming table
	for i := 0; i < (1 << n); i++ {
		for j := 0; j < m; j++ {
			dp[i][j+1] = min(dp[i][j], dp[i][j+1])
			dp[i|key[j+1]][j+1] = min(dp[i|key[j+1]][j+1], dp[i][j]+cost[j+1])
		}
	}

	// Output result
	if dp[(1<<n)-1][m] == INF {
		fmt.Println(-1)
	} else {
		fmt.Println(dp[(1<<n)-1][m])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


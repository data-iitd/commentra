package main

import (
	"fmt"
	"math"
)

const INF = 123456789012

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	key := make([]int, 1005)
	cost := make([]int, 1005)
	dp := make([][]int, (1 << 12) + 5)
	for i := range dp {
		dp[i] = make([]int, 1005)
		for j := range dp[i] {
			dp[i][j] = INF
		}
	}
	dp[0][0] = 0

	for i := 1; i <= m; i++ {
		var b int
		fmt.Scan(&cost[i], &b)
		for j := 0; j < b; j++ {
			var c int
			fmt.Scan(&c)
			key[i] += 1 << (c - 1)
		}
	}

	for i := 0; i < (1 << n); i++ {
		for j := 0; j < m; j++ {
			dp[i][j+1] = min(dp[i][j+1], dp[i][j])
			dp[i|key[j+1]][j+1] = min(dp[i|key[j+1]][j+1], dp[i][j]+cost[j+1])
		}
	}

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

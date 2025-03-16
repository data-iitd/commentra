package main

import (
	"fmt"
	"math"
)

func main() {
	const INF = math.MaxInt32

	// Initialization of the dp slice
	dp := make([]int, 101000)
	for i := range dp {
		dp[i] = INF
	}
	dp[0] = 0

	// Input
	var N, K int
	fmt.Scan(&N, &K)
	h := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&h[i])
	}

	// Dynamic Programming Loop
	for i := 0; i < N; i++ {
		for j := 1; j <= K && i+j < N; j++ {
			dp[i+j] = min(dp[i+j], dp[i]+abs(h[i]-h[i+j]))
		}
	}

	// Output
	fmt.Println(dp[N-1])
}

// Helper functions
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// <END-OF-CODE>

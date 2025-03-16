package main

import (
	"fmt"
	"math"
)

func chmin(a *int, b int) {
	// Minimum update function
	if *a > b {
		*a = b
	}
}

func main() {
	const INF = math.MaxInt32

	// Initialize dynamic programming slice dp with initial value INF for all indices
	dp := make([]int, 101000)
	for i := range dp {
		dp[i] = INF
	}
	dp[0] = 0

	// Read input
	var N, K int // Number of elements in the array and the size of the window
	fmt.Scan(&N, &K)
	h := make([]int, N) // Array of heights
	for i := 0; i < N; i++ {
		fmt.Scan(&h[i]) // Read each height from the input
	}

	// Dynamic programming calculation
	for i := 0; i < N; i++ { // Iterate through all indices i
		for j := 1; j <= K; j++ { // Iterate through all window sizes j
			if i+j < N { // Ensure we don't go out of bounds
				chmin(&dp[i+j], dp[i]+abs(h[i]-h[i+j]))
			}
		}
	}

	// Output the result
	fmt.Println(dp[N-1]) // Print the minimum cost to reach the last index with window size K
}

// abs function to calculate absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

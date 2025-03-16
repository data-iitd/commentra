package main

import (
	"fmt"
	"math"
)

// Minimum update function
func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
	return
}

func main() {
	// Initialize dynamic programming vector dp with initial value INF for all indices
	const INF = int(math.Pow(2, 31)) - 1
	dp := make([]int, 101000, 101000)
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
			// Update dp[i + j] with the minimum cost to reach this index with window size j
			chmin(&dp[i+j], dp[i]+int(math.Abs(float64(h[i]-h[i+j]))))
		}
	}

	// Output the result
	fmt.Println(dp[N-1]) // Print the minimum cost to reach the last index with window size K
}


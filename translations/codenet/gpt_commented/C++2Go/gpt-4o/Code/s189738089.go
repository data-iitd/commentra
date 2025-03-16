package main

import (
	"fmt"
	"math"
)

func main() {
	const INF = math.MaxInt32 // Define a constant for infinity

	// Initialize a dp slice to store the minimum cost to reach each step
	dp := make([]int, 101000)
	for i := range dp {
		dp[i] = INF
	}
	dp[0] = 0 // Base case: cost to reach the first step is 0

	// Input the number of steps (N) and the maximum jump distance (K)
	var N, K int
	fmt.Scan(&N, &K)
	h := make([]int, N) // Slice to store the heights of the steps
	for i := 0; i < N; i++ {
		fmt.Scan(&h[i]) // Read the heights of the steps
	}

	// Dynamic programming to calculate the minimum cost to reach each step
	for i := 0; i < N; i++ {
		// Check possible jumps from the current step
		for j := 1; j <= K; j++ {
			if i+j < N { // Ensure we don't go out of bounds
				dp[i+j] = min(dp[i+j], dp[i]+abs(h[i]-h[i+j]))
			}
		}
	}

	// Output the minimum cost to reach the last step
	fmt.Println(dp[N-1])
}

// Helper function to calculate the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Helper function to calculate the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// <END-OF-CODE>

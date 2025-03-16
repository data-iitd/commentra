package main

import (
	"fmt"
	"math"
)

// Function to update the minimum value
func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func main() {
	// Initialize a dp slice to store the minimum cost to reach each step
	const INF = int(math.Pow(2, 31)) - 1
	dp := make([]int, 101000, 101000)
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
			if i+j < N {
				// Update the minimum cost to reach step i + j
				chmin(&dp[i+j], dp[i]+int(math.Abs(float64(h[i]-h[i+j]))))
			}
		}
	}

	// Output the minimum cost to reach the last step
	fmt.Println(dp[N-1])
}


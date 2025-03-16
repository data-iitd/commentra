package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize a dp vector to store the minimum cost to reach each step
	dp := make([]int, 101000)
	for i := 0; i < len(dp); i++ {
		dp[i] = math.MaxInt32
	}
	dp[0] = 0 // Base case: cost to reach the first step is 0

	// Input the number of steps (N) and the maximum jump distance (K)
	var N, K int
	fmt.Scan(&N, &K)
	h := make([]int, N) // Vector to store the heights of the steps
	for i := 0; i < N; i++ {
		fmt.Scan(&h[i]) // Read the heights of the steps
	}

	// Dynamic programming to calculate the minimum cost to reach each step
	for i := 0; i < N; i++ {
		// Check possible jumps from the current step
		for j := 1; j <= K; j++ {
			// Update the minimum cost to reach step i + j
			if dp[i] + int(math.Abs(float64(h[i]-h[i+j]))) < dp[i+j] {
				dp[i+j] = dp[i] + int(math.Abs(float64(h[i]-h[i+j])))
			}
		}
	}

	// Output the minimum cost to reach the last step
	fmt.Println(dp[N-1])
}


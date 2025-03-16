package main

import "fmt"
import "math"

// Function to find the maximum of two integers
func max(lhs, rhs int) int {
	return int(math.Max(float64(lhs), float64(rhs)))
	// Returns the maximum value between lhs and rhs
}

func main() {
	// Initialize variables N and M to read input
	var (
		N, M int
	)
	// Read input values of N and M from standard input using Scanf
	fmt.Scanf("%d %d", &N, &M)
	// Initialize slices values and weights of size N to read input
	values := make([]int, N)
	weights := make([]int, N)
	// Read input values and weights for each index i from 0 to N-1
	for i := 0; i < N; i++ {
		// Read input values and weights using Scanf and store in respective slices
		fmt.Scanf("%d %d", &weights[i], &values[i])
	}
	// Print N and M for debugging purposes, uncomment if needed
	// fmt.Println(N, M)
	// Print values and weights for debugging purposes, uncomment if needed
	// fmt.Println(values, weights)
	// Initialize 2D slice dp of size (N+1) x (M+1)
	dp := make([][]int, N+1)
	for i := 0; i < N+1; i++ {
		dp[i] = make([]int, M+1)
	}
	// Iterate through each index i from 1 to N and each index j from 0 to M
	for i := 1; i <= N; i++ {
		for j := 0; j <= M; j++ {
			// Initialize dp[i][j] with dp[i-1][j]
			dp[i][j] = dp[i-1][j]
			// If j is greater than or equal to the weight of the current index i-1,
			// update dp[i][j] with the maximum value between dp[i][j] and dp[i-1][j-weights[i-1]]+values[i-1]
			if j >= weights[i-1] {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1])
			}
		}
	}
	// Print the final value of dp[N][M]
	fmt.Println(dp[N][M])
	// End of the code
}
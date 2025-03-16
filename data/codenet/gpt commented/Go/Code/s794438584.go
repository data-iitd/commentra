package main

import "fmt"
import "math"

// max function returns the maximum of two integers.
func max(lhs, rhs int) int {
	return int(math.Max(float64(lhs), float64(rhs)))
}

func main() {
	// Declare variables for the number of items (N) and the maximum weight (M).
	var (
		N, M int
	)

	// Read the number of items and the maximum weight from standard input.
	fmt.Scanf("%d %d", &N, &M)

	// Initialize slices to hold the weights and values of the items.
	values := make([]int, N)
	weights := make([]int, N)

	// Read the weights and values of each item from standard input.
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &weights[i], &values[i])
	}

	// Initialize a 2D slice for dynamic programming table.
	dp := make([][]int, N+1)
	for i := 0; i < N+1; i++ {
		dp[i] = make([]int, M+1)
	}

	// Fill the dynamic programming table.
	for i := 1; i <= N; i++ {
		for j := 0; j <= M; j++ {
			// If the current item is not included, carry forward the previous value.
			dp[i][j] = dp[i-1][j]

			// If the current item's weight is less than or equal to the current capacity.
			if j >= weights[i-1] {
				// Calculate the maximum value by including the current item.
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1])
			}
		}
	}

	// Output the maximum value that can be obtained with the given weight limit.
	fmt.Println(dp[N][M])
}

package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the value of N from the standard input
	A := make([]int64, N+1) // Declare the array A of type int64
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i]) // Read the values of the array A from the standard input
	}

	// Initialize dp array with minimum values
	dp := make([][][]int64, N+1)
	for i := range dp {
		dp[i] = make([][]int64, 2)
		for j := range dp[i] {
			dp[i][j] = make([]int64, 20)
			for k := range dp[i][j] {
				dp[i][j][k] = math.MinInt64 // Initialize with a very large negative value
			}
		}
	}

	// Base case: dp[0][0][10] = 0
	dp[0][0][10] = 0

	// Iterate through all the elements of the array A
	for i := 1; i <= N; i++ {
		for j := 6; j <= 14; j++ { // We only consider the cases where j is between 6 and 14
			if dp[i-1][0][j] != math.MinInt64 { // If dp[i-1][0][j] is not equal to the very large negative value
				dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j]+A[i]) // Update dp[i][1][j+1]
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j]) // Update dp[i][0][j-1]
			}
			if dp[i-1][1][j] != math.MinInt64 { // If dp[i-1][1][j] is not equal to the very large negative value
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j]) // Update dp[i][0][j-1]
			}
		}
	}

	// Calculate the value of T1 and T2
	V := int64(10 + (N/2) - (N - (N / 2)))
	T1 := dp[N][0][V]
	T2 := dp[N][1][V]

	// Print the maximum value of T1 and T2
	fmt.Println(max(T1, T2))
}

// max function to return the maximum of two int64 values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

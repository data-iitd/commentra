package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N + 1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}

	dp := make([][][]int, N + 1)
	for i := 0; i <= N; i++ {
		dp[i] = make([][]int, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([]int, 20)
			for k := 0; k < 20; k++ {
				dp[i][j][k] = math.MinInt64
			}
		}
	}

	// Base case: dp[0][0][10] = 0
	dp[0][0][10] = 0

	// Iterate through all the elements of the array A
	for i := 1; i <= N; i++ {
		for j := 6; j <= 14; j++ { // We only consider the cases where j is between 6 and 14
			if dp[i - 1][0][j] != math.MinInt64 { // If dp[i-1][0][j] is not equal to the very large negative value
				dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]) // Update dp[i][1][j+1] with the maximum of its current value and dp[i-1][0][j] + A[i]
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j]) // Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][0][j]
			}
			if dp[i - 1][1][j] != math.MinInt64 { // If dp[i-1][1][j] is not equal to the very large negative value
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j]) // Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][1][j]
			}
		}
	}

	// Calculate the value of T1 and T2
	V := 10 + (N / 2) - (N - (N / 2))
	T1 := dp[N][0][V]
	T2 := dp[N][1][V]

	// Print the maximum value of T1 and T2
	fmt.Println(max(T1, T2))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}


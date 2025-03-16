package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int64, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize dp array
	dp := make([][][]int64, N+1)
	for i := range dp {
		dp[i] = make([][]int64, 2)
		for j := range dp[i] {
			dp[i][j] = make([]int64, 20)
			for k := range dp[i][j] {
				dp[i][j][k] = math.MinInt64
			}
		}
	}
	dp[0][0][10] = 0

	// Dynamic Programming Transition
	for i := 1; i <= N; i++ {
		for j := 6; j <= 14; j++ {
			if dp[i-1][0][j] != math.MinInt64 {
				dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j]+A[i])
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j])
			}
			if dp[i-1][1][j] != math.MinInt64 {
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j])
			}
		}
	}

	// Calculate the Result
	V := 10 + (N/2) - (N - (N / 2))
	T1 := dp[N][0][V]
	T2 := dp[N][1][V]
	fmt.Println(max(T1, T2))
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>

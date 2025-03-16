package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	A := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scanf("%d", &A[i])
	}
	dp := make([][][20]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([][20]int, 2)
		for j := 0; j < 20; j++ {
			dp[i][0][j] = -math.MaxInt64
			dp[i][1][j] = -math.MaxInt64
		}
	}
	dp[0][0][10] = 0
	for i := 1; i <= N; i++ {
		for j := 6; j <= 14; j++ {
			if dp[i-1][0][j]!= -math.MaxInt64 {
				dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j]+A[i])
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j])
			}
			if dp[i-1][1][j]!= -math.MaxInt64 {
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j])
			}
		}
	}

	V := 10 + (N/2) - (N-(N/2))
	T1 := dp[N][0][V]
	T2 := dp[N][1][V]
	fmt.Println(max(T1, T2))
}


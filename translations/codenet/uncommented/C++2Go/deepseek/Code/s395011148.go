package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}
	const maxN = 1 << 18
	const max20 = 20
	dp := make([][2][max20]int64, maxN)
	for i := 0; i <= N; i++ {
		for j := 0; j < max20; j++ {
			dp[i][0][j] = -(1 << 60)
			dp[i][1][j] = -(1 << 60)
		}
	}
	dp[0][0][10] = 0
	for i := 1; i <= N; i++ {
		for j := 6; j <= 14; j++ {
			if dp[i-1][0][j] != -(1<<60) {
				if dp[i][1][j+1] < dp[i-1][0][j]+int64(A[i]) {
					dp[i][1][j+1] = dp[i-1][0][j] + int64(A[i])
				}
				if dp[i][0][j-1] < dp[i-1][0][j] {
					dp[i][0][j-1] = dp[i-1][0][j]
				}
			}
			if dp[i-1][1][j] != -(1<<60) {
				if dp[i][0][j-1] < dp[i-1][1][j] {
					dp[i][0][j-1] = dp[i-1][1][j]
				}
			}
		}
	}

	V := 10 + (N / 2) - (N - (N / 2))
	T1 := dp[N][0][V]
	T2 := dp[N][1][V]
	fmt.Println(int64(math.Max(float64(T1), float64(T2))))
}


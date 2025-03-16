package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	h := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&h[i])
	}

	dp := make([]int, N)
	dp[0] = 0
	for i := 0; i < N; i++ {
		for j := 1; j <= K; j++ {
			if dp[i]+math.Abs(float64(h[i]-h[i+j])) < dp[i+j] {
				dp[i+j] = dp[i] + math.Abs(float64(h[i]-h[i+j]))
			}
		}
	}

	fmt.Println(dp[N-1])
}


package main

import (
	"fmt"
	"math"
)

const INF = 1 << 30

func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func main() {
	// Initialization of the dp array
	dp := make([]int, 101000)
	for i := range dp {
		dp[i] = INF
	}
	dp[0] = 0
	// input
	var N, K int
	fmt.Scan(&N, &K)
	h := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&h[i])
	}

	// Dynamic Programming Loop
	for i := 0; i < N; i++ {
		for j := 1; j <= K; j++ {
			if i+j < N {
				chmin(&dp[i+j], dp[i]+int(math.Abs(float64(h[i]-h[i+j]))))
			}
		}
	}

	// Output
	fmt.Println(dp[N-1])
}


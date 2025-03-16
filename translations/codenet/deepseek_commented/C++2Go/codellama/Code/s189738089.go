package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialization of the dp array
	dp := make([]int, 101000)
	for i := 0; i < 101000; i++ {
		dp[i] = math.MaxInt32
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
		for j := 1; j < K+1; j++ {
			if dp[i+j] > dp[i]+int(math.Abs(float64(h[i])-float64(h[i+j]))) {
				dp[i+j] = dp[i] + int(math.Abs(float64(h[i])-float64(h[i+j])))
			}
		}
	}

	// Output
	fmt.Println(dp[N-1])
}


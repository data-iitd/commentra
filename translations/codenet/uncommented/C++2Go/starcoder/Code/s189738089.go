package main

import (
	"fmt"
	"math"
)

func main() {
	var dp []int
	dp = make([]int, 101000)
	for i := 0; i < 101000; i++ {
		dp[i] = math.MaxInt32
	}
	dp[0] = 0
	var N, K int
	fmt.Scanf("%d %d\n", &N, &K)
	h := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &h[i])
	}
	for i := 0; i < N; i++ {
		for j := 1; j <= K; j++ {
			if dp[i+j] > dp[i] + int(math.Abs(float64(h[i] - h[i+j]))){
				dp[i+j] = dp[i] + int(math.Abs(float64(h[i] - h[i+j])))
			}
		}
	}
	fmt.Println(dp[N-1])
}


package main

import (
	"fmt"
	"math"
)

// Function to return the minimum of two integers
func chmin(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func main() {
	var n int
	fmt.Scan(&n)

	dp := make([]int, n)
	h := make([]int, n)

	for i := 0; i < n; i++ {
		dp[i] = math.MaxInt32
	}

	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
	}

	dp[0] = 0

	for i := 1; i < n; i++ {
		if i == 1 {
			dp[1] = int(math.Abs(float64(h[1] - h[0])))
		} else {
			dp[i] = chmin(dp[i-1]+int(math.Abs(float64(h[i]-h[i-1]))), dp[i-2]+int(math.Abs(float64(h[i]-h[i-2]))))
		}
	}

	fmt.Println(dp[n-1])
}


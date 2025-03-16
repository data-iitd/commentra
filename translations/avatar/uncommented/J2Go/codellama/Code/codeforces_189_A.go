package main

import (
	"fmt"
	"math"
)

func main() {
	var n, a, b, c int
	fmt.Scan(&n, &a, &b, &c)
	arr := []int{a, b, c}
	dp := make([]int, 4010)
	for i := 0; i < n; i++ {
		dp[i] = math.MinInt32
	}
	dp[0] = 0
	for i := 0; i < 3; i++ {
		for j := arr[i]; j < len(dp); j++ {
			dp[j] = int(math.Max(float64(dp[j]), float64(dp[j-arr[i]]+1)))
		}
	}
	fmt.Println(dp[n])
}


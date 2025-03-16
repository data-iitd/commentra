package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	maxn := 4010
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	arr := []int{a, b, c}
	dp := make([]int, maxn)

	for i := 0; i < n; i++ {
		dp[i] = int(^uint(0) >> 1) // Set to Integer.MIN_VALUE
	}
	dp[0] = 0

	for i := 0; i < 3; i++ {
		for j := arr[i]; j < len(dp); j++ {
			dp[j] = max(dp[j], dp[j-arr[i]]+1)
		}
	}

	fmt.Println(dp[n])
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// <END-OF-CODE>

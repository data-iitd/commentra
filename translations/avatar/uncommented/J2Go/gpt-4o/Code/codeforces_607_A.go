package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	beacon := make([]int, 1000001)
	dp := make([]int, 1000001)
	max := 0

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		beacon[a] = b
	}

	if beacon[0] != 0 {
		dp[0] = 1
	}

	for i := 1; i < 1000001; i++ {
		if beacon[i] != 0 && beacon[i] < i {
			dp[i] = dp[i-beacon[i]-1] + 1
		} else if beacon[i] != 0 {
			dp[i] = 1
		} else {
			dp[i] = dp[i-1]
		}
		max = maxInt(max, dp[i])
	}

	fmt.Print(n - max)
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

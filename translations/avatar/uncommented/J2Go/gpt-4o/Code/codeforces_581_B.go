package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	dp := make([]int64, n+1)
	for i := range dp {
		dp[i] = -1
	}
	dp[n-1] = a[n-1]

	for i := n - 1; i >= 0; i-- {
		dp[i] = max(dp[i+1], a[i])
	}

	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Print(0, " ")
		} else {
			fmt.Print(dp[i+1]-a[i]+1, " ")
		}
	}
	fmt.Println()
}

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

// <END-OF-CODE>

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

	// Step 5: Initialize a dynamic programming array
	dp := make([]int64, n+1)
	for i := range dp {
		dp[i] = -1
	}

	// Step 6: Fill the dynamic programming array
	dp[n-1] = a[n-1]
	for i := n - 1; i >= 0; i-- {
		dp[i] = max(dp[i+1], a[i])
	}

	// Step 7: Calculate the result
	for i := 0; i < n; i++ {
		if a[i] > dp[i+1] {
			fmt.Print(0, " ")
		} else {
			fmt.Print(dp[i+1]-a[i]+1, " ")
		}
	}

	// Step 8: Print the result
	fmt.Println()
}

// max function to find the maximum of two int64 values
func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

// Step 9: Debugging (optional)
// Uncomment the following function for debugging
/*
func debug(args ...interface{}) {
	fmt.Println(args...)
}
*/


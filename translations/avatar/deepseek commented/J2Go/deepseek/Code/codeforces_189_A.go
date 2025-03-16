package main

import (
	"fmt"
)

func main() {
	// Initialize a Scanner object to read input from the user
	var n, a, b, c int
	fmt.Scan(&n, &a, &b, &c)
	
	// Store the coin values in an array
	arr := []int{a, b, c}
	
	// Initialize a dp array with all elements set to -1
	maxn := 4010
	dp := make([]int, maxn)
	for i := 0; i < maxn; i++ {
		dp[i] = -1
	}
	
	// Set the base case where dp[0] is 0
	dp[0] = 0
	
	// Iterate over the coin values and update the dp array
	for i := 0; i < 3; i++ {
		for j := arr[i]; j < maxn; j++ {
			if dp[j-arr[i]] != -1 {
				dp[j] = max(dp[j], dp[j-arr[i]]+1)
			}
		}
	}
	
	// Print the value of dp[n]
	fmt.Println(dp[n])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

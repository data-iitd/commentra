package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
	var n int
	fmt.Scan(&n)
	
	// Define the maximum size for the dp array
	const maxn = 4010
	
	// Initialize a dp array to store the maximum number of items that can be formed
	dp := make([]int, maxn)
	
	// Set all dp values to -1 to indicate uncomputed states
	for i := 0; i < maxn; i++ {
		dp[i] = -1
	}
	
	// Base case: zero items can be formed with zero size
	dp[0] = 0
	
	// Read three integer values (a, b, c) which represent the sizes of items
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	
	// Store the sizes of items in an array for easier access
	arr := []int{a, b, c}
	
	// Iterate through each item size (a, b, c)
	for _, item := range arr {
		// Update the dp array for each possible size from the current item size
		for j := item; j < maxn; j++ {
			// Calculate the maximum number of items that can be formed
			if dp[j-item] != -1 && dp[j] < dp[j-item]+1 {
				dp[j] = dp[j-item] + 1
			}
		}
	}
	
	// Output the maximum number of items that can be formed with size n
	fmt.Println(dp[n])
}

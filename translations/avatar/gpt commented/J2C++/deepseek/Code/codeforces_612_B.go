package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
	var n int
	fmt.Scan(&n)
	
	// Initialize a dp array to store the indices of the input elements
	dp := make([]int, 200001)
	
	// Populate the dp array with the indices of the input elements
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		dp[x] = i
	}
	
	// Initialize a variable to accumulate the result
	var ans int64 = 0
	
	// Calculate the total distance between consecutive elements in the dp array
	for i := 2; i <= n; i++ {
		// Add the absolute difference of indices of consecutive elements to ans
		ans += int64(abs(dp[i] - dp[i - 1]))
	}
	
	// Output the final result
	fmt.Println(ans)
}

// Helper function to calculate the absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}


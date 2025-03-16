package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a variable to read input from the console
	var n int
	// Read the number of elements to be processed
	fmt.Scan(&n)

	// Initialize a dp slice to store the indices of the input elements
	dp := make([]int, 200001)

	// Populate the dp slice with the indices of the input elements
	for i := 0; i < n; i++ {
		var x int
		// Read the next integer and store its index in the dp slice
		fmt.Scan(&x)
		dp[x] = i
	}

	// Initialize a variable to accumulate the result
	var ans int64 = 0

	// Calculate the total distance between consecutive elements in the dp slice
	for i := 2; i <= n; i++ {
		// Add the absolute difference of indices of consecutive elements to ans
		ans += int64(math.Abs(float64(dp[i] - dp[i-1])))
	}

	// Output the final result
	fmt.Println(ans)
}

// <END-OF-CODE>

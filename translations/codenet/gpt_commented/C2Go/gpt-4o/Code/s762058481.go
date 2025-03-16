package main

import (
	"fmt"
	"math"
)

// Function to return the minimum of two integers
func chmin(a, b int) int {
	if a > b {
		return b // Return b if it is smaller than a
	}
	return a // Otherwise, return a
}

func main() {
	var n int
	// Read the number of elements (n) from standard input
	fmt.Scan(&n)

	// Declare slices for dynamic programming and heights
	dp := make([]int, n) // dp[i] will hold the minimum cost to reach step i
	h := make([]int, n)  // h[i] will hold the height of step i

	// Initialize the dp slice with a large value (10000)
	for i := 0; i < n; i++ {
		dp[i] = 10000
	}

	// Read the heights of each step from standard input
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
	}

	// Base case: the cost to reach the first step is 0
	dp[0] = 0

	// Fill the dp slice with the minimum costs to reach each step
	for i := 1; i < n; i++ {
		// Calculate the cost to reach step i from step i-1 and step i-2
		if i == 1 {
			dp[1] = int(math.Abs(float64(h[1] - h[0]))) // Cost to jump from step 0 to step 1
		} else {
			// Choose the minimum cost between jumping from step i-1 or i-2
			dp[i] = chmin(dp[i-1]+int(math.Abs(float64(h[i]-h[i-1]))),
				dp[i-2]+int(math.Abs(float64(h[i]-h[i-2]))))
		}
	}

	// Output the minimum cost to reach the last step
	fmt.Println(dp[n-1])
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"math"
)

// Function to return the smaller value between two integers
func chmin(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements
	dp := make([]int, n) // Declare the dp slice
	h := make([]int, n)  // Declare the h slice

	for i := 0; i < n; i++ {
		dp[i] = 10000 // Initialize the dp slice to a large value
	}

	for i := 0; i < n; i++ {
		fmt.Scan(&h[i]) // Read the heights into the h slice
	}

	dp[0] = 0 // Starting point with no cost
	for i := 1; i < n; i++ {
		if i == 1 {
			dp[1] = int(math.Abs(float64(h[1] - h[0]))) // Cost to reach the first step
		} else {
			dp[i] = chmin(dp[i-1]+int(math.Abs(float64(h[i]-h[i-1]))), dp[i-2]+int(math.Abs(float64(h[i]-h[i-2])))) // Calculate the minimum cost to reach the current step
		}
	}
	fmt.Println(dp[n-1]) // Print the minimum cost to reach the last step
}

// <END-OF-CODE>

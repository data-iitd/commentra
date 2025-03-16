package main

import (
	"fmt"
)

func main() {
	// Create a scanner for input
	var n int
	fmt.Scan(&n)

	// Initialize a slice to hold the input values
	a := make([]int64, n)

	// Populate the slice with input values
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize a dp slice to store the maximum values
	dp := make([]int64, n+1)

	// Fill the dp slice with -1 to indicate uninitialized values
	for i := range dp {
		dp[i] = -1
	}

	// Set the last element of dp to the last element of a
	dp[n-1] = a[n-1]

	// Fill the dp slice with the maximum values from the end to the beginning
	for i := n - 1; i >= 0; i-- {
		dp[i] = max(dp[i+1], a[i])
	}

	// Iterate through the original slice to calculate the output
	for i := 0; i < n; i++ {
		// If the current element is greater than the next maximum, print 0
		if a[i] > dp[i+1] {
			fmt.Print(0, " ")
		} else {
			// Otherwise, calculate and print the difference to the next maximum
			fmt.Print(dp[i+1]-a[i]+1, " ")
		}
	}

	// Print a new line after all outputs
	fmt.Println()
}

// Utility function to return the maximum of two int64 values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>

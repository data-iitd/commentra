package main

import (
	"fmt"
)

func main() {
	var A, B, C, K int64 // Declare variables for input

	// Read input values from the standard input
	fmt.Scan(&A, &B, &C, &K)

	// Check if the sum of A and B is greater than or equal to K
	if A+B >= K {
		// If true, print the minimum value between A and K
		fmt.Println(min(A, K))
	} else {
		// If false, calculate the difference between K and the sum of A and B,
		// and subtract it from A to get the required value
		fmt.Println(A - (K - (A + B)))
	}
}

// min function to return the minimum of two int64 values
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>

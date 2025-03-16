package main

import (
	"fmt"
	"math"
)

// Function to check and update the minimum value of a variable
func chmin(a *int, b int) bool {
	if *a > b {
		*a = b
		return true
	}
	return false
}

// Function to check and update the maximum value of a variable
func chmax(a *int, b int) bool {
	if *a < b {
		*a = b
		return true
	}
	return false
}

func main() {
	// Declare variables to store input values
	var A, B, C, K int
	fmt.Scan(&A, &B, &C, &K)

	// Check if the sum of A and B is greater than or equal to K
	if A+B >= K {
		// Output the minimum of A and K
		if A < K {
			fmt.Println(A)
		} else {
			fmt.Println(K)
		}
	} else {
		// Calculate the result by subtracting the excess amount from A
		fmt.Println(A - (K - (A + B)))
	}
}


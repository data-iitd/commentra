package main

import (
	"fmt"
	"math"
)

// Function to update the value of 'a' to 'b' if 'b' is less than 'a'
func chmin(a *int, b int) bool {
	if *a > b {
		*a = b // Update 'a' to 'b'
		return true // Indicate that 'a' was changed
	}
	return false // Indicate that 'a' was not changed
}

// Function to update the value of 'a' to 'b' if 'b' is greater than 'a'
func chmax(a *int, b int) bool {
	if *a < b {
		*a = b // Update 'a' to 'b'
		return true // Indicate that 'a' was changed
	}
	return false // Indicate that 'a' was not changed
}

func main() {
	var A, B, C, K int
	fmt.Scan(&A, &B, &C, &K) // Read input values for A, B, C, and K

	// Check if the sum of A and B is greater than or equal to K
	if A + B >= K {
		// If true, output the minimum of A and K
		if A < K {
			fmt.Println(A)
		} else {
			fmt.Println(K)
		}
	} else {
		// If false, calculate and output the remaining value after subtracting (K - (A + B)) from A
		fmt.Println(A - (K - (A + B)))
	}
}


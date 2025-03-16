package main

import (
	"fmt"
)

func main() {
	// Declare variables to store input values
	var A, B, C, K int64
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

// <END-OF-CODE>

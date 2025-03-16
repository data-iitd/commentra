
package main

import (
	"fmt"
)

func main() {
	var A, B, C, K int64 // Declare variables for input
	fmt.Scan(&A, &B, &C, &K) // Read input values for A, B, C, and K

	// Check if the sum of A and B is greater than or equal to K
	if A+B >= K {
		// If true, output the minimum of A and K
		fmt.Println(min(A, K))
	} else {
		// If false, calculate and output the remaining value after subtracting (K - (A + B)) from A
		fmt.Println(A - (K - (A + B)))
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}


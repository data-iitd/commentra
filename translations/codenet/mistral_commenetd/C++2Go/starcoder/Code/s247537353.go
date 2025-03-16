<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Chmin and chmax are helper functions to update a variable with the minimum or maximum of it and another value, respectively.
func chmin(a, b int) bool {
	if a > b {
		a = b
		return true
	}
	return false
}

func chmax(a, b int) bool {
	if a < b {
		a = b
		return true
	}
	return false
}

func main() {
	// Read input values from the standard input
	A, B, C, K := readInput()

	// Check if the sum of A and B is greater than or equal to K
	if A+B >= K {
		// If true, print the minimum value between A and K
		fmt.Println(min(A, K))
	} else {
		// If false, calculate the difference between K and the sum of A and B,
		// and subtract it from A to get the required value
		fmt.Println(A - (K-(A+B)))
	}
}

// readInput reads input from stdin
func readInput() (int, int, int, int) {
	var A, B, C, K int
	fmt.Scanf("%d %d %d %d", &A, &B, &C, &K)
	return A, B, C, K
}

// min returns the minimum value of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// END-OF-CODE


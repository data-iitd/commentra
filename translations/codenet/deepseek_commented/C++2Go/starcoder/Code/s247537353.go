<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Function to check and update the minimum value of a variable
func chmin(a, b int) bool {
	if a > b {
		a = b
		return true
	}
	return false
}

// Function to check and update the maximum value of a variable
func chmax(a, b int) bool {
	if a < b {
		a = b
		return true
	}
	return false
}

// Define constants for maximum values
const INF = math.MaxInt32
const MOD = 1000000007

// Macro to iterate over all elements in a container
func all(a []int) []int {
	b := make([]int, len(a))
	for i := range a {
		b[i] = a[i]
	}
	return b
}

func main() {
	// Declare variables to store input values
	var A, B, C, K int
	fmt.Scanf("%d %d %d %d", &A, &B, &C, &K)

	// Check if the sum of A and B is greater than or equal to K
	if A+B >= K {
		// Output the minimum of A and K
		fmt.Println(min(A, K))
	} else {
		// Calculate the result by subtracting the excess amount from A
		fmt.Println(A - (K - (A + B)))
	}
}


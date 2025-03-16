package main

import (
	"fmt"
	"os"
)

func main() {
	// Initializing the arrays m and f with zeros for all indices up to N
	const N = 368
	m := make([]int, N)
	f := make([]int, N)

	// Reading the number of operations from the standard input
	var operations int
	fmt.Scan(&operations)

	// Processing each operation
	for i := 0; i < operations; i++ {
		var x string
		var a, b int
		fmt.Scan(&x, &a, &b)
		b++ // Increment b by 1

		// If the operation is 'M', updating the m array accordingly
		if x == "M" {
			m[a] += 2
			m[b] -= 2
		} else { // If the operation is 'F', updating the f array accordingly
			f[a] += 2
			f[b] -= 2
		}
	}

	// Initializing three variables a, b, and c with zeros
	a, b, c := 0, 0, 0

	// Calculating the prefix sums of m and f arrays
	for i := 0; i < N; i++ {
		a += m[i]
		b += f[i]
		// Finding the minimum of a and b and updating the variable c
		if min(a, b) > c {
			c = min(a, b)
		}
	}

	// Printing the result, which is the minimum of the prefix sums of m and f arrays
	fmt.Println(c)
}

// Helper function to find the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// <END-OF-CODE>

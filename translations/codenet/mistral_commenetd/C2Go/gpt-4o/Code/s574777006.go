package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n, q, sum int
	var x [10000]int
	var y [500]int

	// Read the number of elements in the array x
	fmt.Scan(&n)

	// Allocate memory for array x
	for i := 0; i < n; i++ {
		// Read each element of array x
		fmt.Scan(&x[i])
	}

	// Read the number of queries
	fmt.Scan(&q)

	// Allocate memory for array y
	for i := 0; i < q; i++ {
		// Read each element of array y
		fmt.Scan(&y[i])
	}

	// Initialize sum to zero
	sum = 0

	// Check if each element of array y is present in array x and increment sum if found
	for i := 0; i < q; i++ {
		for j := 0; j < n; j++ {
			// Check if current element of y is equal to current element of x
			if y[i] == x[j] {
				// Increment sum if found
				sum++
				// Break out of inner loop as soon as a match is found
				break
			}
		}
	}

	// Print the value of sum
	fmt.Println(sum)
}

// <END-OF-CODE>

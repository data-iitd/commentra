package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n, q, sum int
	var x [10000]int
	var y [500]int

	// Read the number of elements in array x
	fmt.Scan(&n)

	// Read n elements into array x
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}

	// Read the number of queries
	fmt.Scan(&q)

	// Read q elements into array y
	for i := 0; i < q; i++ {
		fmt.Scan(&y[i])
	}

	// Initialize sum to count how many elements in y are found in x
	for i := 0; i < q; i++ {
		// Check each element in y against all elements in x
		for j := 0; j < n; j++ {
			// If a match is found, increment sum and break the inner loop
			if y[i] == x[j] {
				sum++
				break
			}
		}
	}

	// Output the total count of matches found
	fmt.Println(sum)
}

// <END-OF-CODE>

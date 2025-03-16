package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n, a, m, M, c int64

	// Initialize cumulative sum and set initial min and max values
	c = 0 // Cumulative sum of the numbers
	m = 100000000 // Initialize minimum value to a large number
	M = -100000000 // Initialize maximum value to a small number

	// Read the number of elements
	fmt.Scan(&n)

	// Loop through each element to read and process
	for i := int64(1); i <= n; i++ {
		// Read the current number
		fmt.Scan(&a)

		// Update maximum value if the current number is greater
		if a > M {
			M = a
		}

		// Update minimum value if the current number is smaller
		if a < m {
			m = a
		}

		// Add the current number to the cumulative sum
		c += a
	}

	// Print the minimum, maximum, and cumulative sum
	fmt.Printf("%d %d %d\n", m, M, c)
}

// <END-OF-CODE>

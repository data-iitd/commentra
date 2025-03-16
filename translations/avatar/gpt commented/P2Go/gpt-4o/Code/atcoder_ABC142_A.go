package main

import (
	"fmt"
)

func nextInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func main() {
	// Read the number of iterations or elements
	n := nextInt()

	// Initialize a counter for odd indices
	t := 0

	// Loop through the range of n
	for i := 0; i < n; i++ {
		// Check if the current index (i + 1) is odd
		if (i + 1) % 2 != 0 {
			t++ // Increment the counter for odd indices
		}
	}

	// Calculate and print the ratio of odd indices to total elements
	fmt.Println(float64(t) / float64(n))
}

// <END-OF-CODE>

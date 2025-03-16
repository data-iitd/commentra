package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int
	fmt.Scan(&x) // Read first integer input
	fmt.Scan(&y) // Read second integer input
	fmt.Scan(&a) // Read third integer input
	fmt.Scan(&b) // Read fourth integer input

	count := 0 // Initialize counter to keep track of valid pairs

	// Nested loops to iterate through possible pairs (i, j)
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue // Skip pairs where i is not greater than j
			}
			count++ // Increment counter for each valid pair
		}
	}

	fmt.Println(count) // Print the total count of valid pairs

	// Print each valid pair
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue // Skip pairs where i is not greater than j
			}
			fmt.Println(i, j) // Print each valid pair
		}
	}
}

// <END-OF-CODE>

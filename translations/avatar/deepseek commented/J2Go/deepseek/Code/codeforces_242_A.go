package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b) // Read integer inputs

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


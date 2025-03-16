package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int
	// Read input values for x, y, a, and b
	fmt.Scan(&x, &y, &a, &b)

	// Initialize a slice to store valid game pairs
	var games [][2]int

	// Iterate over the range from a to x (inclusive)
	for i := a; i <= x; i++ {
		// Skip the iteration if i is less than or equal to b
		if i <= b {
			continue
		} else {
			// Iterate over the range from b to y (inclusive)
			for j := b; j <= y; j++ {
				// Check if the current i is greater than j
				if i > j {
					// If the condition is met, append the pair (i, j) to the games slice
					games = append(games, [2]int{i, j})
				}
			}
		}
	}

	// Print the total number of valid game pairs found
	fmt.Println(len(games))

	// Print each valid game pair
	for _, pair := range games {
		fmt.Printf("%d %d\n", pair[0], pair[1])
	}
}

// <END-OF-CODE>

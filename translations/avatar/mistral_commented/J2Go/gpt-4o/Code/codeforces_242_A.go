package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the console
	var x, y, a, b int

	// Read four integers from the console
	fmt.Scan(&x, &y, &a, &b)

	// Initialize a counter variable
	count := 0

	// Find the number of pairs (i, j) that satisfy the condition i < j
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			// If i is less than or equal to j, continue to the next iteration of the inner loop
			if i <= j {
				continue
			}

			// Increment the counter if the condition is satisfied
			count++
		}
	}

	// Print the result
	fmt.Println(count)

	// Print all pairs (i, j) that satisfy the condition i < j
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			// If i is less than or equal to j, print the pair
			if i <= j {
				fmt.Println(i, j)
			}
		}
	}
}

// <END-OF-CODE>

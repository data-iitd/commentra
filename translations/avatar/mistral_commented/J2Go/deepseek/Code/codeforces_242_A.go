package main

import (
	"fmt"
)

func main() {
	// Read four integers from the console
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)

	// Initialize a counter variable
	count := 0

	// Find the number of pairs (i, j) that satisfy the condition i < j
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			// If i is less than j, continue to the next iteration of the inner loop
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
			// If i is less than j, print the pair
			if i <= j {
				continue
			}

			fmt.Println(i, j)
		}
	}
}


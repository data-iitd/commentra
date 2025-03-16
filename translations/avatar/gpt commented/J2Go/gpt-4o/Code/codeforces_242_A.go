package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold the input values
	var x, y, a, b int

	// Read four integers from the user
	fmt.Scan(&x, &y, &a, &b)

	// Initialize a counter to keep track of valid pairs
	count := 0

	// First nested loop to iterate through the range [a, x]
	for i := a; i <= x; i++ {
		// Second nested loop to iterate through the range [b, y]
		for j := b; j <= y; j++ {
			// Skip the iteration if i is less than or equal to j
			if i <= j {
				continue
			}

			// Increment the count for each valid pair (i, j)
			count++
		}
	}

	// Output the total count of valid pairs
	fmt.Println(count)

	// Second set of nested loops to print the valid pairs
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			// Skip the iteration if i is less than or equal to j
			if i <= j {
				continue
			}

			// Print the valid pair (i, j)
			fmt.Println(i, j)
		}
	}
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n, tmp int // n for number of inputs, tmp for temporary input storage
	min := 1000000
	max := -1000000
	sum := 0 // Initialize min, max, and sum

	// Read the number of integers to be processed
	fmt.Scan(&n)

	// Loop to read n integers
	for i := 0; i < n; i++ {
		// Read the next integer
		fmt.Scan(&tmp)

		// Update min if the current number is smaller
		if min > tmp {
			min = tmp
		}

		// Update max if the current number is larger
		if max < tmp {
			max = tmp
		}

		// Add the current number to the sum
		sum += tmp
	}

	// Print the minimum, maximum, and sum of the numbers
	fmt.Printf("%d %d %d\n", min, max, sum)
}

// <END-OF-CODE>

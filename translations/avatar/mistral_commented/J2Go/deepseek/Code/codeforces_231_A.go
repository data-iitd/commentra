package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t) // Read the number of test cases from the standard input

	// Initialize a counter variable to keep track of the number of valid cases
	count := 0

	// Read the number of test cases and process each one in the for loop
	for i := 0; i < t; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c) // Read the three integers from the standard input

		// Check if any of the given integers are equal to 1. If so, increment the counter.
		if a == 1 && b == 1 || a == 1 && c == 1 || b == 1 && c == 1 || a == 1 && b == 1 && c == 1 {
			count++ // Increment the counter if any of the given integers are equal to 1
		}
	}

	// Print the value of the counter to the standard output
	fmt.Println(count)
}


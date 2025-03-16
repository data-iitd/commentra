package main

import (
	"fmt"
)

func main() {
	var t int // Declare the number of test cases
	fmt.Scan(&t) // Read the number of test cases from standard input

	// Initialize a counter variable to keep track of the number of valid cases
	count := 0

	// Process each test case
	for i := 0; i < t; i++ {
		var a, b, c int // Declare the three integers
		fmt.Scan(&a, &b, &c) // Read the integers from standard input

		// Check if any of the given integers are equal to 1. If so, increment the counter.
		if (a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1) {
			count++ // Increment the counter if any of the given integers are equal to 1
		}
	}

	// Print the value of the counter to the standard output
	fmt.Println(count)
}

// <END-OF-CODE>

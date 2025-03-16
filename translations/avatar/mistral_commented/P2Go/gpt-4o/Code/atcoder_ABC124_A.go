package main

import (
	"fmt"
)

func main() {
	// Get two integers as input from the user, separated by a space
	var a, b int
	fmt.Scan(&a, &b)

	// Initialize a variable 'c' to store the sum of the larger numbers in each iteration
	c := 0

	// Loop through the given condition for 2 times
	for i := 0; i < 2; i++ {
		// Calculate the sum of the larger number in each iteration and add it to the variable 'c'
		if a > b {
			c += a
			a--
		} else {
			c += b
			b--
		}
	}

	// Print the final result
	fmt.Println(c)
}

// <END-OF-CODE>

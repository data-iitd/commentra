package main

import (
	"fmt"
)

func main() {
	// Read two integers from input and assign them to variables a and b
	var a, b int
	fmt.Scan(&a, &b)

	// Initialize the variable 'hole' to represent the current hole position
	hole := 1

	// Initialize a counter 'i' to track the number of iterations
	i := 0

	// Set a flag 'check' to control the while loop
	check := true

	// Continue looping until the condition is met
	for check {
		// Check if the current hole position is greater than or equal to b
		if hole >= b {
			// If so, exit the loop
			check = false
		} else {
			// Calculate the new hole position based on the formula
			hole = a*(i+1) - i

			// Increment the iteration counter
			i++
		}
	}

	// Print the total number of iterations (i) when the loop ends
	fmt.Println(i)
}

// <END-OF-CODE>

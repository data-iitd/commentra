package main

import (
	"fmt"
)

func main() {
	// Declare variables for input number, loop counter, and a temporary variable
	var n, i, a int

	// Read an integer input from the user
	fmt.Scan(&n)

	// Loop from 1 to n (inclusive)
	for i = 1; i <= n; i++ {
		// Assign the current loop index to a
		a = i

		// Check if the current number is divisible by 3
		if a%3 == 0 {
			// If divisible by 3, print the number
			fmt.Printf(" %d", i)
		} else {
			// If not divisible by 3, check if it contains the digit '3'
			for a > 0 {
				// Check if the last digit of a is 3
				if a%10 == 3 {
					// If it contains the digit '3', print the number
					fmt.Printf(" %d", i)
					// Set a to 0 to exit the loop
					a = 0
				}
				// Remove the last digit from a
				a = a / 10
			}
		}
	}

	// Print a newline character after all numbers have been processed
	fmt.Println()
}


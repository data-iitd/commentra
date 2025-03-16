package main

import (
	"fmt"
)

func main() {
	// Declare a variable for input number
	var n int

	// Read an integer input from the user
	fmt.Scan(&n)

	// Loop from 1 to n (inclusive)
	for i := 1; i <= n; i++ {
		// Check if the current number is divisible by 3
		if i%3 == 0 {
			// If divisible by 3, print the number
			fmt.Printf(" %d", i)
		} else {
			// If not divisible by 3, check if it contains the digit '3'
			a := i
			for a > 0 {
				// Check if the last digit of a is 3
				if a%10 == 3 {
					// If it contains the digit '3', print the number
					fmt.Printf(" %d", i)
					break
				}
				// Remove the last digit from a
				a = a / 10
			}
		}
	}

	// Print a newline character after all numbers have been processed
	fmt.Println()
}

// <END-OF-CODE>

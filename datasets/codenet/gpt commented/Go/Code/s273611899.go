package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold the input values
	var n, x int

	// Infinite loop to continuously read input until termination condition is met
	for {
		// Read two integers from the standard input
		fmt.Scan(&n, &x)

		// Check for the termination condition: both n and x are zero
		if n == 0 && x == 0 {
			break // Exit the loop if the termination condition is met
		}

		// Initialize a counter to keep track of the number of valid combinations
		c := 0

		// Iterate through all possible combinations of three distinct integers
		for i := 1; i <= n-2; i++ { // First integer
			for j := i + 1; j <= n-1; j++ { // Second integer
				for k := j + 1; k <= n; k++ { // Third integer
					// Check if the sum of the three integers equals x
					if i+j+k == x {
						c++ // Increment the counter if the condition is satisfied
					}
				}
			}
		}

		// Output the count of valid combinations for the current input
		fmt.Println(c)
	}
}

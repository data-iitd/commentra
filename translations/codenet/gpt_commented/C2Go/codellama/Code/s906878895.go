package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold two integers and intermediate results
	var a, b, x, w int

	// Continuously read pairs of integers until EOF (End of File) is reached
	for {
		// Read a pair of integers
		_, err := fmt.Scanf("%d %d", &a, &b)

		// Check if there was an error reading the input
		if err != nil {
			// If there was an error, print the error message
			fmt.Println(err)
			// Break out of the loop
			break
		}

		// Calculate the sum of the two integers
		x = a + b

		// Initialize a counter for the number of digits in the sum
		w = 0

		// Count the number of digits in the sum (x)
		for x > 0 {
			// Increment the digit counter
			w++
			// Remove the last digit from x by dividing by 10
			x /= 10
		}

		// Print the number of digits in the sum
		fmt.Println(w)
	}
}


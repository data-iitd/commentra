package main

import (
	"fmt"
)

func main() {
	var a, b int

	// Continuously read pairs of integers until EOF (End of File) is reached
	for {
		// Read two integers from standard input
		_, err := fmt.Scanf("%d %d", &a, &b)
		if err != nil {
			break // Exit the loop if there is an error (EOF)
		}

		// Calculate the sum of the two integers
		x := a + b

		// Initialize a counter for the number of digits in the sum
		w := 0

		// Count the number of digits in the sum (x)
		if x == 0 {
			w = 1 // Special case for 0
		} else {
			for x > 0 {
				w++       // Increment the digit counter
				x /= 10  // Remove the last digit from x by dividing by 10
			}
		}

		// Print the number of digits in the sum
		fmt.Println(w)
	}
}

// <END-OF-CODE>

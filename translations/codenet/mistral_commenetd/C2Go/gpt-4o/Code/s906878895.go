package main

import (
	"fmt"
)

func main() {
	var a, b, x, w int
	// Declare four integer variables: a, b, x, and w

	for {
		_, err := fmt.Scanf("%d %d", &a, &b)
		if err != nil {
			break
		}
		// Read two integers a and b from input

		x = a + b
		// Assign the sum of a and b to x

		w = 0
		// Initialize w to zero

		for x > 0 {
			w++
			// Increment w each time through the loop
			x /= 10
			// Divide x by 10 to get the next digit
		}
		fmt.Println(w)
		// Print the value of w, which represents the number of digits in the sum of a and b
	}
	// This loop continues to read input until an error occurs (EOF)

	return
}
// The main function returns to indicate successful execution
// <END-OF-CODE>

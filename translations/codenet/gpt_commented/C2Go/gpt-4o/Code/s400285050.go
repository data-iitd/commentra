package main

import (
	"fmt"
)

// Function 'you' that computes the greatest common divisor (GCD) using the Euclidean algorithm
func you(x int, y int) int {
	var z int

	// Infinite loop to perform the Euclidean algorithm
	for {
		z = x % y // Calculate the remainder of x divided by y
		x = y     // Update x to be y
		y = z     // Update y to be the remainder

		// Break the loop if y becomes zero or negative
		if y <= 0 {
			break
		}
	}

	// Return the last non-zero value of x, which is the GCD
	return x
}

func main() {
	// Declare variables to hold input values and result
	var x, y int

	// Read two integers from user input
	fmt.Scanf("%d %d", &x, &y)

	// Call the 'you' function with the larger and smaller of the two integers
	var z int
	if x >= y {
		z = you(x, y) // If x is greater than or equal to y, pass x and y to 'you'
	} else {
		z = you(y, x) // Otherwise, pass y and x to 'you'
	}

	// Print the result returned from the 'you' function
	fmt.Println(z)
}

// <END-OF-CODE>

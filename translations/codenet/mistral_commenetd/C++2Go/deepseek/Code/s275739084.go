package main

import (
	"fmt"
)

func main() {
	// Declare two integer variables A and B
	var A, B int

	// Read the values of A and B from the standard input
	fmt.Scan(&A, &B)

	// Declare an integer variable C and assign the sum of A and B to it
	C := A + B

	// Check if both A and B are not divisible by 3
	if A%3 != 0 && B%3 != 0 {
		// Check if their sum C is also not divisible by 3
		if C%3 != 0 {
			// If all conditions are met, print "Impossible" to the standard output
			fmt.Println("Impossible")
		} else {
			// Otherwise, print "Possible" to the standard output
			fmt.Println("Possible")
		}
	}
}


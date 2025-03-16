package main

import (
	"fmt"
)

func main() {
	// Read two integers from input and assign them to variables a and b
	var a, b int
	fmt.Scan(&a, &b)

	// Initialize a variable c to accumulate the result
	c := 0

	// Loop for 2 iterations
	for i := 0; i < 2; i++ {
		// Add the maximum of a and b to c
		if a > b {
			c += a
			a-- // Decrease a
		} else {
			c += b
			b-- // Decrease b
		}
	}

	// Print the final accumulated value of c
	fmt.Println(c)
}

// <END-OF-CODE>

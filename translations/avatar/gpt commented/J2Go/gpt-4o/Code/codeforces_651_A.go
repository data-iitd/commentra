package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Read two integers from input
	c := 0 // Initialize counter for the number of operations

	// Check for the special case where both a and b are 1
	if a == 1 && b == 1 {
		fmt.Println(0) // Output 0 operations needed
		return
	}

	// Loop until both a and b are non-positive
	for a >= 1 || b >= 1 {
		// If a is greater than or equal to b, perform operation on a
		if a >= b {
			b++  // Increment b
			a -= 2 // Decrement a by 2
		} else {
			// If b is greater than a, perform operation on b
			a++  // Increment a
			b -= 2 // Decrement b by 2
		}

		// Check if either a or b has become non-positive
		if a <= 0 || b <= 0 {
			c++ // Increment operation counter and break
			break
		}
		c++ // Increment operation counter
	}

	// Output the total number of operations performed
	fmt.Println(c)
}

// <END-OF-CODE>

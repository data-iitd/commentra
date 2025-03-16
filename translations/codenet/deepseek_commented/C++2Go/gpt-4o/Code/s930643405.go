package main

import (
	"fmt"
)

func main() {
	// Define an array to keep track of unavailable digits
	d := make([]bool, 10)

	// Define variables to store the number and the number of unavailable digits
	var n, k int

	// Read the initial number and the number of unavailable digits
	fmt.Scan(&n, &k)

	// Mark the unavailable digits
	for i := 0; i < k; i++ {
		var a int
		fmt.Scan(&a)
		d[a] = true
	}

	// Loop until a valid number is found
	for {
		// Copy the current number to a temporary variable and initialize the check flag
		x := n
		hantei := true

		// Check each digit of the number
		for x > 0 {
			// If a digit is unavailable, set the check flag to false and break the loop
			if d[x%10] {
				hantei = false
				break
			}
			// Move to the next digit
			x /= 10
		}

		// If the number is valid, print it and break the loop
		if hantei {
			fmt.Println(n)
			break
		}

		// Increment the number and check again
		n++
	}
}

// <END-OF-CODE>

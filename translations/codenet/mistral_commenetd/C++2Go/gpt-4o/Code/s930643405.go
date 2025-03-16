package main

import (
	"fmt"
)

func main() {
	// Initialize some variables
	var n, k int
	d := make([]bool, 10) // A boolean slice to keep track of digits that have been seen

	// Read input
	fmt.Scan(&n, &k)

	// Check each digit in the input number 'k' times
	for i := 0; i < k; i++ {
		var a int // A variable to store the digit to check
		fmt.Scan(&a) // Read the digit from the input
		d[a] = true // Mark the digit as seen
	}

	// Keep generating numbers until a valid one is found
	for {
		x := n // Initialize a variable 'x' to store the current number being checked
		hantei := true // A flag to indicate if the current number is valid

		// Check each digit in the number 'x'
		for x > 0 {
			// If the current digit has already been seen, then the number is not valid
			if d[x%10] {
				hantei = false
				break
			}
			x /= 10 // Move to the next digit
		}

		// If the current number is valid, print it and exit the loop
		if hantei {
			fmt.Println(n)
			break
		}

		// If the current number is not valid, increment 'n' and continue checking
		n++
	}
}

// <END-OF-CODE>

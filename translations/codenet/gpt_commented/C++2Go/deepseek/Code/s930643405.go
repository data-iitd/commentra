package main

import (
	"fmt"
)

// Define a pair type for convenience
type P struct {
	first, second int
}

// Array to track forbidden digits
var d [10]bool // Initialize all digits as not forbidden
var n, k int // Variables to hold the input number and the count of forbidden digits
var hantei bool // Flag to determine if the current number is valid

func main() {
	// Read the initial number 'n' and the count of forbidden digits 'k'
	fmt.Scan(&n, &k)

	// Read the forbidden digits and mark them in the array
	for i := 0; i < k; i++ {
		var a int
		fmt.Scan(&a) // Input each forbidden digit
		d[a] = true // Mark the digit as forbidden
	}

	// Infinite loop to find the next valid number
	for {
		x := n
		hantei = true // Reset the validity flag for the new number

		// Check each digit of the number 'x'
		for x > 0 {
			// If the current digit is forbidden
			if d[x % 10] {
				hantei = false // Mark the number as invalid
				break // Exit the digit checking loop
			}
			x /= 10 // Remove the last digit
		}

		// If the number is valid (no forbidden digits found)
		if hantei {
			fmt.Println(n) // Output the valid number
			break // Exit the infinite loop
		}
		n++ // Increment the number and check the next one
	}
}


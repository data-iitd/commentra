package main

import (
	"fmt"
)

func main() {
	// Ask the user to input an integer value
	var n int
	fmt.Scan(&n)

	// Initialize a variable i and set its value to n
	for i := n; i > 0; i-- {
		// Check if n is divisible by the current value of i
		if n%i == 0 {
			// If the condition is true, update the value of n to i
			n = i
			// Print the current value of i
			fmt.Print(i, " ")
		}
	}
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	// Declare two integer variables to hold the input values
	var a, b int

	// Read two integer values from user input
	fmt.Scan(&a, &b)

	// If the first input value is 1, set it to 14
	if a == 1 {
		a = 14
	}

	// If the second input value is 1, set it to 14
	if b == 1 {
		b = 14
	}

	// Compare the two values and print the result
	if a < b {
		// If 'a' is less than 'b', print "Bob"
		fmt.Println("Bob")
	} else if a > b {
		// If 'a' is greater than 'b', print "Alice"
		fmt.Println("Alice")
	} else {
		// If 'a' is equal to 'b', print "Draw"
		fmt.Println("Draw")
	}
}


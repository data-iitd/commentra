package main

import (
	"fmt"
)

func main() {
	// Create a variable to hold the first integer input
	var a int
	// Create a variable to hold the second integer input
	var b int

	// Read the first integer input from the user
	fmt.Scan(&a)
	// Read the second integer input from the user
	fmt.Scan(&b)

	// Check if the first integer 'a' is positive
	if a > 0 {
		// If 'a' is positive, print the message "Positive"
		fmt.Println("Positive")
	} else if b >= 0 {
		// If 'b' is non-negative, print the message "Zero"
		fmt.Println("Zero")
	} else if (b-a+1)%2 == 0 {
		// If the difference is even, print the message "Positive"
		fmt.Println("Positive")
	} else {
		// Else, print the message "Negative"
		fmt.Println("Negative")
	}
}

// <END-OF-CODE>

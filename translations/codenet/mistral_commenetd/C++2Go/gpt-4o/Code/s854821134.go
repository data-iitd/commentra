package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Begin the main function
	var a, b int // Declare two integer variables a and b
	fmt.Scan(&a, &b) // Read the values of a and b from standard input

	// Check if both a and b are less than or equal to 8
	if a <= 8 && b <= 8 {
		fmt.Println("Yay!") // If the condition is true, print "Yay!" to the standard output
	} else {
		fmt.Println(":(") // If the condition is false, print ":(" to the standard output
	}

	// End the main function
}

// <END-OF-CODE>

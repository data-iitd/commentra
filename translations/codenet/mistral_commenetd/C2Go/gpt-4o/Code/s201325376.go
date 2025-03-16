package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // The entry point of the program
	var a, b, c, count int // Declare variables a, b, c, and count
	fmt.Scanf("%d%d%d", &a, &b, &c) // Read three integers a, b, and c from standard input
	count = 0 // Initialize the count variable to zero

	// The following for loop iterates from the value of 'a' to the value of 'b'
	for i := a; i <= b; i++ {
		// Check if 'c' is divisible by 'i'
		if c%i == 0 {
			// If it is, increment the count variable
			count++
		}
	}

	// Print the value of 'count' to the standard output
	fmt.Println(count)

	// End of the program
}

// <END-OF-CODE>

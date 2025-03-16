package main
// Import the main package

import (
	"fmt"
	// Import the fmt package for formatted I/O
)

func main() {
	var x int
	// Declare an integer variable x

	fmt.Scanf("%d", &x)
	// Read an integer value from the standard input and store it in variable x

	fmt.Printf("%d\n", x*x*x)
	// Print the result of x cubed to the standard output
}

// Indicate successful termination of the program

package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() { // Begin the main function
	var a int // Declare an integer variable named 'a'

	fmt.Scan(&a) // Read an integer value from the user and store it in variable 'a'

	// Calculate the value of the expression (a + (a * a) + (a * a * a)) and store it in the output buffer
	fmt.Println(a + (a * a) + (a * a * a))
}


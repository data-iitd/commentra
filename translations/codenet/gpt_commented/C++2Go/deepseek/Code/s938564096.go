package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() {
	var r int // Declare an integer variable 'r' to store user input
	fmt.Scan(&r) // Read an integer value from standard input and store it in 'r'
	
	// Calculate the square of 'r' and print the result
	fmt.Println(r * r) // Output the square of 'r'
}


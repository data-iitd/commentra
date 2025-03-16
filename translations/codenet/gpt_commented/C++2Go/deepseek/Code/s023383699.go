package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() { // Main function where the program execution begins
	var x int // Declare an integer variable 'x' to store user input
	fmt.Scan(&x) // Read an integer value from the user and store it in 'x'
	
	// Calculate the cube of 'x' and print the result
	fmt.Println(x * x * x) // Output the cube of 'x'
}


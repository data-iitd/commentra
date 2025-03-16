package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() {
	var a int // Declare an integer variable 'a' to store user input

	// Prompt the user to enter a value for 'a'
	fmt.Print("Enter a number: ")
	fmt.Scan(&a) // Read the input value from the user and store it in 'a'

	// Calculate the expression a + a^2 + a^3 and output the result
	result := a + (a * a) + (a * a * a)
	fmt.Println(result)
}


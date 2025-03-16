package main // Package declaration

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() {
	// Declare variable
	var n int

	fmt.Print("Enter the value of n: ")
	fmt.Scan(&n) // Read an integer value from the user and store it in variable n

	// Calculate and print the result
	fmt.Printf("The result is: %d\n", 24+(24-n))

	// Indicate successful execution of the program
}

// <END-OF-CODE>

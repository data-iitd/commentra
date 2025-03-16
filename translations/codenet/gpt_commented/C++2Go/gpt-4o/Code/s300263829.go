package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Main function where the execution of the program begins
	var a, b int // Declare two integer variables a and b to store user input

	// Prompt the user to enter two integers
	fmt.Print("Enter two integers: ") 
	fmt.Scan(&a, &b) // Read two integers from user input and store them in variables a and b

	// Calculate the product of a and b and display the result
	fmt.Println("The product is:", a*b) 
	
	// No explicit return statement is needed in Go's main function
}

// <END-OF-CODE>

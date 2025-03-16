package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Declare the main function
	var a, b int // Declare two integer variables a and b
	fmt.Scan(&a, &b) // Read two integers from standard input and assign them to variables a and b
	fmt.Println(a * b) // Multiply the values of variables a and b and print the result to standard output
}

// <END-OF-CODE>

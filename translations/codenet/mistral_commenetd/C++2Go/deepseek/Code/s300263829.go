package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() {
	var a, b int // Declare two integer variables a and b
	fmt.Scan(&a, &b) // Read two integers from the standard input and assign them to variables a and b
	fmt.Println(a * b) // Multiply the values of variables a and b and print the result to the standard output
}


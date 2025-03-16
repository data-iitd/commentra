package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() { // The main function is the entry point of the program
	var r int // Declare an integer variable named "r"

	// Read the value of "r" from the standard input using fmt.Scan
	fmt.Scan(&r)

	// Output the square of "r" to the standard output using fmt.Println and the + operator
	fmt.Println(r * r)

	// The program ends with a return statement, which is not strictly necessary since main returns 0 by default if no return statement is present
}

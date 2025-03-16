// Package declaration
package main

// Importing required packages
import (
	"fmt"
)

// Function definition for main function
func main() {
	// Variable declaration and initialization
	var a, b, h int

	// Reading input values from the standard input
	fmt.Scan(&a, &b, &h)

	// Calculating the result
	result := (a + b) * h / 2

	// Printing the result to the standard output
	fmt.Println(result)
}

// End of the code

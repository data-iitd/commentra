package main

import (
	"fmt" // Importing the fmt package for formatted I/O operations
)

func main() {
	// Declare variables to hold the lengths of the two bases and the height
	var a, b, h int
	
	// Read input values for the two bases (a and b) and the height (h) from the user
	fmt.Scan(&a, &b, &h)

	// Calculate the area of the trapezoid using the formula: Area = (a + b) * h / 2
	// and print the result to the console
	fmt.Println((a + b) * h / 2)
}

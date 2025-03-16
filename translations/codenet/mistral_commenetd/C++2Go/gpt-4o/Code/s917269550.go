package main // Declare the main package

import (
	"fmt" // Import the fmt package for input/output
	"math" // Import the math package for abs() function
)

func main() {
	var x, y int64 // Declare two int64 variables, x and y, to store user inputs

	// Read user inputs from standard input using Scan
	fmt.Scan(&x, &y)

	// Check if the absolute difference between x and y is less than or equal to 1
	if math.Abs(float64(x-y)) <= 1 {
		// If the condition is true, print "Brown" to the standard output
		fmt.Println("Brown")
	} else {
		// If the condition is false, print "Alice" to the standard output
		fmt.Println("Alice")
	}
}

// <END-OF-CODE>

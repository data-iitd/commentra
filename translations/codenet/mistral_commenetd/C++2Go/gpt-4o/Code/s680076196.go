package main // Declare the main package

import (
	"fmt" // Import the fmt package for input/output
)

func main() {
	// Declare variables a, b, c, and d of type int
	var a, b, c, d int

	// Read values of variables a, b, c, and d from standard input
	fmt.Scan(&a, &b, &c, &d)

	// Calculate the difference between a and c, and the difference between b and d
	differenceAB := int64(a) - int64(c)
	differenceCD := int64(b) - int64(d)

	// Multiply the differences and print the result to standard output
	fmt.Println(differenceAB * differenceCD)
}

// <END-OF-CODE>

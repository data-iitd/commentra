package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() {
	var a, b, x, y int // Declare four integer variables: a, b, x, and y

	fmt.Scan(&a, &b) // Read two integers from the standard input and store them in variables a and b
	// The Scan function is used to read input values and store them in the provided variables

	x = 2*a + 2*b // Multiply variables a and b by 2, and then add the results together and store the result in variable x

	y = a * b // Multiply variables a and b and store the result in variable y

	fmt.Printf("%d %d\n", y, x) // Print the values of variables y and x to the standard output, separated by a space and followed by a newline character
}


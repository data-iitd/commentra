package main

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() {
	var a int // Declare a variable 'a' of type int to store user input
	fmt.Scan(&a) // Read an integer value from standard input and store it in 'a'

	// Calculate the area of a circle with radius 'a' using the formula: Area = 3 * a^2
	fmt.Println(3 * a * a) // Print the calculated area to the standard output
}

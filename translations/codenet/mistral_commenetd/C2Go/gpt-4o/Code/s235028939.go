package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // The entry point of the program
	// Declare two integer variables n and m
	var n, m int

	// Use fmt.Scanf to read two integers from the standard input and store them in n and m variables
	fmt.Scanf("%d %d", &n, &m)

	// Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
	result := (n - 1) * (m - 1)

	// Use fmt.Printf to print the result to the standard output
	fmt.Printf("%d\n", result)

	// Indicate that the program has run successfully and terminate it
}

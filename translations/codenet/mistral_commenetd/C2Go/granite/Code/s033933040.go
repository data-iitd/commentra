
package main

import "fmt" // Import the standard input/output library

// Declare variables
func main() {
	var a, b, mawari, menseki int // Declare variables a, b, mawari, and menseki as integers

	// Read input values for variables a and b from the user
	fmt.Scan(&a, &b)
	// Assign the variable mawari the sum of the squares of a and b
	mawari = a + a + b + b
	// Assign the variable menseki the product of a and b
	menseki = a * b
	// Print the values of menseki and mawari to the console
	fmt.Println(menseki, mawari)
}

// 
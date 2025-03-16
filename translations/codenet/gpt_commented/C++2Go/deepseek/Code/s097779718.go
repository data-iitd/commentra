package main

import (
	"fmt"
)

// Function to compute the Greatest Common Divisor (GCD) using Euclid's algorithm
func Euclid(x, y int) int {
	var tmp int

	// Ensure x is the larger number
	if x < y {
		tmp = x // Store the smaller number in tmp
		x = y   // Assign the larger number to x
		y = tmp // Assign the smaller number to y
	}

	// If y divides x evenly, y is the GCD
	if x%y == 0 {
		return y
	}

	// Recursively call Euclid with y and the remainder of x divided by y
	return Euclid(y, x%y)
}

func main() {
	var A, B int // Declare variables to hold the two input numbers
	fmt.Scan(&A, &B) // Read input values for A and B

	// Calculate and output the Least Common Multiple (LCM) using the formula LCM(A, B) = (A * B) / GCD(A, B)
	fmt.Println((A * B) / Euclid(A, B))
}


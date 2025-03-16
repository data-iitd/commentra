package main

import (
	"fmt"
)

// Function to find the greatest common divisor (GCD) of two numbers using Euclid's algorithm
func Euclid(x, y int64) int64 {
	var tmp int64 // Variable to store the temporary value

	// Swap x and y if x is smaller than y
	if x < y {
		tmp = x
		x = y
		y = tmp
	}

	// If x is divisible by y, return y as the GCD
	if x%y == 0 {
		return y
	}

	// Recursively call Euclid function with y and the remainder of x divided by y
	return Euclid(y, x%y)
}

func main() {
	var A, B int64 // Declare variables to store input numbers

	// Read input values of A and B from the standard input
	fmt.Scan(&A, &B)

	// Calculate the product of A and B and print the result divided by their GCD
	fmt.Println((A * B) / Euclid(A, B))
}


package main

import (
	"fmt"
)

// Function to compute the Greatest Common Divisor (GCD) of two numbers
func G(a, b int) int {
	// Continue looping until b becomes 0
	for b != 0 {
		// Update a and b using the Euclidean algorithm
		a, b = b, a%b
	}
	// Return the GCD
	return a
}

// Function to compute the Least Common Multiple (LCM) of two numbers
func L(a, b int) int {
	// Calculate LCM using the relationship between GCD and LCM
	return a * b / G(a, b)
}

func main() {
	var x, y, a, b int
	// Read input values
	fmt.Scan(&x, &y, &a, &b)

	// Calculate the LCM of x and y
	lcm := L(x, y)

	// Calculate and print the count of multiples of LCM in the range [a, b]
	count := b/lcm - (a-1)/lcm
	fmt.Println(count)
}

// <END-OF-CODE>

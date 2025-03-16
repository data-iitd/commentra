package main

import (
	"fmt"
)

// Function to find the greatest common divisor (GCD) of two numbers using Euclidean algorithm
func G(a, b int) int {
	// Continue the loop until the remainder is zero
	for a%b != 0 {
		// Swap a and b, and update a with the new value of b
		a, b = b, a%b
	}
	// Return the greatest common divisor (GCD)
	return b
}

// Function to find the least common multiple (LCM) of two numbers
func L(a, b int) int {
	// Find the GCD of a and b using the G function
	gcd := G(a, b)
	// Return the product of a and b divided by their GCD
	return a * b / gcd
}

func main() {
	var x, y, a, b int
	// Read input as a list of strings, split it by spaces and convert each element to an integer
	fmt.Scan(&x, &y, &a, &b)

	// Find the least common multiple (LCM) of x and y using the L function
	lcm := L(x, y)

	// Calculate the result by subtracting (a-1) from b divided by lcm
	result := b/lcm - (a-1)/lcm
	fmt.Println(result)
}

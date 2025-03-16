package main

import (
	"fmt"
)

// Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
func Euclid(x, y int) int {
	var tmp int

	// Ensure x is greater than y
	if x < y {
		tmp = x
		x = y
		y = tmp
	}

	// Base case: if x is divisible by y, return y
	if x%y == 0 {
		return y
	}

	// Recursive case: apply the Euclidean algorithm
	return Euclid(y, x%y)
}

func main() {
	var A, B int

	// Read two integers from standard input
	fmt.Scan(&A, &B)

	// Calculate and output the least common multiple (LCM) of A and B
	fmt.Println((A * B) / Euclid(A, B))
}


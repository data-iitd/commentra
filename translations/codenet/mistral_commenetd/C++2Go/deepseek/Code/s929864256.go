package main

import (
	"fmt"
	"math"
)

// Constants definition
const INF = 1 << 60 // Infinite value for long long int
const MOD = 1000000007 // Modulus value for modular arithmetic

// Main function
func main() {
	// Initialize variables
	var a, b int

	// Read input values from standard input
	fmt.Scan(&a, &b)

	// Calculate the maximum value among a+b, a-b, and a*b
	result := math.Max(float64(a+b), math.Max(float64(a-b), float64(a*b)))

	// Output the result to standard output
	fmt.Println(result)
}


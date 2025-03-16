package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int64 // Declare two int64 integers a and b
	fmt.Scan(&a, &b) // Read values for a and b from standard input

	// Calculate the maximum of the sum, difference, and product of a and b
	maxValue := math.Max(float64(a+b), math.Max(float64(a-b), float64(a*b))) // Find the maximum value
	fmt.Println(int64(maxValue)) // Output the maximum value
}

// <END-OF-CODE>

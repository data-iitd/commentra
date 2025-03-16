package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize variables
	var a, b int64

	// Read input values from standard input
	fmt.Scan(&a, &b)

	// Calculate the maximum value among a+b, a-b, and a*b
	result := int64(math.Max(float64(a+b), math.Max(float64(a-b), float64(a*b))))

	// Output the result to standard output
	fmt.Println(result)
}

// <END-OF-CODE>

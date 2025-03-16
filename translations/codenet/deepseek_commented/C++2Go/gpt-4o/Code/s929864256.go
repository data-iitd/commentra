package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int64
	fmt.Scan(&a, &b) // Read two int64 integers from standard input

	// Compute the maximum value among a+b, a-b, and a*b
	maxValue := math.Max(float64(a+b), math.Max(float64(a-b), float64(a*b)))
	fmt.Println(int64(maxValue)) // Print the maximum value
}

// <END-OF-CODE>

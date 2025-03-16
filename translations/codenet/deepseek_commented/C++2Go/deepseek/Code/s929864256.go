package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Read two integers from standard input

	// Compute the maximum value among a+b, a-b, and a*b
	maxVal := math.Min(float64(a+b), math.Max(float64(a-b), float64(a*b)))
	fmt.Println(maxVal) // Print the maximum value
}


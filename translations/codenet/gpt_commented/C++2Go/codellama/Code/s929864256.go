package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int64 // Declare two long long integers a and b
	fmt.Scan(&a, &b) // Read values for a and b from standard input

	// Calculate the maximum of the sum, difference, and product of a and b
	fmt.Println(int64(math.Max(float64(a+b), math.Max(float64(a-b), float64(a*b))))) // Output the maximum value
}


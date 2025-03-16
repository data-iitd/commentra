package main

import (
	"fmt"
	"math"
)

func main() {
	// Read input values for r, D, and x from the user
	var r, D, x int
	fmt.Scan(&r, &D, &x)

	// Iterate over a range of values from 2 to 11 (inclusive)
	for i := 2; i <= 11; i++ {
		// Calculate and print the result based on the formula
		// The formula computes a value using the current iteration index i,
		// the input values r, D, and x, and prints the integer result
		fmt.Println(int(math.Pow(float64(r), float64(i-1)) * float64(x+D/(1-r)) - D/(1-r)))
	}
}


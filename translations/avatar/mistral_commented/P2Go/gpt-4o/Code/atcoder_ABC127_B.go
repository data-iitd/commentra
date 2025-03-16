package main

import (
	"fmt"
	"math"
)

func main() {
	// Take three integers as input from the user
	var r, D, x int
	fmt.Scan(&r, &D, &x)

	// Iterate through the range of numbers from 2 to 11 (12 is excluded)
	for i := 2; i < 12; i++ {
		// Calculate the expression and print the integer result
		result := math.Round(float64(r^(i-1))*(float64(x)+float64(D)/(1-float64(r))) - float64(D)/(1-float64(r)))
		fmt.Println(int(result))
	}
}

// The expression inside the loop calculates the value of a recursive formula
// r^(i-1) * (x + D / (1 - r)) - D / (1 - r)

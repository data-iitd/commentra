package main

import (
	"fmt"
	"math"
)

func main() {
	var r, D, x int
	// Read input values for r, D, and x from the user
	fmt.Scan(&r, &D, &x)

	// Iterate over a range of values from 2 to 11 (inclusive)
	for i := 2; i <= 11; i++ {
		// Calculate and print the result based on the formula
		result := int(float64(r^(i-1))*(float64(x)+float64(D)/(1-float64(r))) - float64(D)/(1-float64(r)))
		fmt.Println(result)
	}
}

// <END-OF-CODE>

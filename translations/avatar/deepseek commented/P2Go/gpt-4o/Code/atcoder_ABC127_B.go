package main

import (
	"fmt"
	"math"
)

func main() {
	var r, D, x int
	// Read three integers r, D, and x from input
	fmt.Scan(&r, &D, &x)

	// Loop from 2 to 11 (inclusive)
	for i := 2; i <= 11; i++ {
		// Calculate the value using the given formula and print the integer result
		result := int(float64(r) * math.Pow(float64(r), float64(i-1)) * (float64(x) + float64(D)/(1-float64(r))) - float64(D)/(1-float64(r)))
		fmt.Println(result)
	}
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"math"
)

func main() {
	// Ask the user for an integer input
	var x int
	fmt.Scan(&x)

	// Calculate the greatest common divisor (gcd) of 360 and the user input x
	gcdValue := gcd(360, x)

	// Print the result of the division of 360 by the gcd
	fmt.Println(360 / gcdValue)
}

// gcd function to calculate the greatest common divisor
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// <END-OF-CODE>

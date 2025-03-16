package main

import (
	"fmt"
)

func main() {
	var a, b int
	// Read two integers from input
	fmt.Scan(&a, &b)

	// Calculate the minimum of a and b, and the half of the difference between the maximum and minimum values
	minValue := a
	if b < a {
		minValue = b
	}
	maxValue := a
	if b > a {
		maxValue = b
	}
	halfDifference := (maxValue - minValue) / 2

	// Print the minimum value and the calculated half difference
	fmt.Println(minValue, halfDifference)
}

// <END-OF-CODE>

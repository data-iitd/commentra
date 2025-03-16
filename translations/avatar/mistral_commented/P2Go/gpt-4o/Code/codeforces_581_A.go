package main

import (
	"fmt"
)

func main() {
	var a, b int
	// Get user input and split by space
	fmt.Scan(&a, &b)

	// Find the minimum value between 'a' and 'b'
	minValue := a
	if b < a {
		minValue = b
	}

	// Find the maximum value between 'a' and 'b'
	maxValue := a
	if b > a {
		maxValue = b
	}

	// Print the minimum value and the average of the difference between minimum and maximum values
	fmt.Println(minValue, (maxValue-minValue)/2)
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold the input values
	var a, b, x int64

	// Read three long long integers from standard input
	fmt.Scan(&a, &b, &x)

	// Calculate the number of multiples of x in the range [a, b]
	s := (b / x - a / x)

	// If 'a' is a multiple of 'x', include it in the count
	if a % x == 0 {
		s++
	}

	// Print the result: the total count of multiples of x in the range
	fmt.Println(s)
}


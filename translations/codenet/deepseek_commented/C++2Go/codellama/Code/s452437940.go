package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	// Declare variables to store user input
	var a, b, x int64

	// Read three long long integers from standard input
	fmt.Scan(&a, &b, &x)

	// Calculate the number of multiples of x between a and b inclusive
	s := (b / x - a / x)

	// Check if a is a multiple of x and adjust the count accordingly
	if a%x == 0 {
		s++
	}

	// Print the result
	fmt.Println(s)
}


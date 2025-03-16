package main

import (
	"fmt"
	"math"
)

func main() {
	// Take an integer input from the user
	var n int
	fmt.Scan(&n)

	// Initialize a variable x to 1
	x := 1

	// Continue looping until the base-2 logarithm of n is an integer
	for math.Log2(float64(n)) != math.Floor(math.Log2(float64(n))) {
		// Increment x by 1
		x++
		// Update n by subtracting 2 raised to the power of the integer part of the base-2 logarithm of n
		n -= int(math.Pow(2, math.Floor(math.Log2(float64(n)))))
	}

	// Print the value of x
	fmt.Println(x)
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	var a, b, c, d int // Declare four integer variables to hold input values

	// Read four integer values from standard input
	fmt.Scan(&a, &b, &c, &d)

	// Calculate the product of the differences between the first two and the last two integers
	// This represents the area of a rectangle defined by the points (a, b) and (c, d)
	fmt.Println((a - c) * (b - d))
}


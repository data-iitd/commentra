package main

import (
	"fmt"
	"math"
)

func main() {
	// Include necessary headers
	// This code uses the standard input/output library and the math library for mathematical constants and functions

	var r float64
	// Read the input value for the radius of the circle
	fmt.Scan(&r)

	// Calculate the area of the circle (πr^2) and the circumference (2πr)
	area := r * r * math.Pi
	circumference := 2 * math.Pi * r

	// Print the results to the standard output
	fmt.Println(area, circumference)
}


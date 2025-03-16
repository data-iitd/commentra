package main

import (
	"fmt"
	"math"
)

func main() {
	var r float64

	// Read a value for 'r' from the standard input
	fmt.Scan(&r)

	// Calculate the area and circumference of a circle with radius 'r'
	area := r * r * math.Pi
	circumference := 2 * math.Pi * r

	// Print the results to the standard output
	fmt.Printf("%f %f\n", area, circumference)
}


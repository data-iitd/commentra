package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables for radius, area, and circumference
	var r float64 // radius
	var s, l float64 // area and circumference
	var p float64 = 3.141592653589 // value of pi

	// Read the radius from user input
	fmt.Scan(&r)

	// Calculate the area of the circle using the formula: area = π * r^2
	s = r * r * p

	// Calculate the circumference of the circle using the formula: circumference = 2 * π * r
	l = 2 * p * r

	// Print the calculated area and circumference
	fmt.Println(s, l)
}


package main

import (
	"fmt"
	"math"
)

func main() {
	// Read input values for hours (h), minutes (m), and lengths (a, b)
	var a, b, h, m int
	fmt.Scan(&a, &b, &h, &m)

	// Calculate the angle C between the hour and minute hands of the clock
	C := math.Abs(360.0/60.0*float64(m) - 360.0/12.0*float64(h) - 360.0/12.0/60.0*float64(m))

	// If the angle is greater than 180 degrees, find the smaller angle
	if C > 180 {
		C = 360 - C
	}

	// Calculate the cosine of angle C in radians
	cosC := math.Cos(C * math.Pi / 180.0)

	// Use the Law of Cosines to calculate the length of the third side of the triangle
	// formed by the lengths a, b, and the angle C
	result := math.Sqrt(float64(a*a) + float64(b*b) - 2*float64(a)*float64(b)*cosC)

	// Print the result
	fmt.Println(result)
}

// <END-OF-CODE>

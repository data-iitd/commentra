package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, h, m int
	fmt.Scan(&a, &b, &h, &m)

	// Calculate the angle C between hour hand and minute hand
	C := math.Abs(360.0/60.0*float64(m) - 360.0/12.0*float64(h) - 360.0/12.0/60.0*float64(m))
	if C > 180 {
		// If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
		C = 360 - C
	}

	// Calculate the cosine of angle C
	cosC := math.Cos(C * math.Pi / 180.0)

	// Calculate and print the length of the side of the right triangle formed by the hour and minute hands
	result := math.Sqrt(float64(a*a + b*b - 2*a*b*cosC))
	fmt.Println(result)
}

// <END-OF-CODE>

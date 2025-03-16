package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, h, m int
	// Taking input values for the lengths of the sides of the triangle and the time
	fmt.Scan(&a, &b, &h, &m)

	C := math.Abs(360.0/60.0*float64(m) - 360.0/12.0*float64(h) - 360.0/12.0/60.0*float64(m))
	// Calculating the angle C between the hour and minute hands of a clock

	if C > 180 {
		C = 360 - C
	}
	// Adjusting the angle C if it is greater than 180 degrees

	cosC := math.Cos(C * math.Pi / 180.0)
	// Calculating the cosine of angle C in radians

	result := math.Sqrt(float64(a*a + b*b - 2*a*b*cosC))
	// Calculating the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines

	fmt.Println(result)
	// Printing the result
}

// <END-OF-CODE>

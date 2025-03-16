package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, h, m float64
	fmt.Scan(&a, &b, &h, &m)

	// Calculate the angle C between the hour and minute hands of the clock
	C := math.Abs(360/60*m - 360/12*h - 360/12/60*m)

	// If the angle is greater than 180 degrees, find the smaller angle
	if C > 180 {
		C = 360 - C
	}

	// Calculate the cosine of angle C in radians
	cosC := math.Cos(C * math.Pi / 180)

	// Use the Law of Cosines to calculate the length of the third side of the triangle
	// formed by the lengths a, b, and the angle C
	result := math.Sqrt(a*a + b*b - 2*a*b*cosC)
	fmt.Println(result)
}


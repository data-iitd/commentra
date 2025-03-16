
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var a, b, h, m int
	fmt.Scan(&a, &b, &h, &m)
	// Taking input values for the lengths of the sides of the triangle and the time

	C := math.Abs(360/60*float64(m) - 360/12*float64(h) - 360/12/60*float64(m))
	// Calculating the angle C between the hour and minute hands of a clock

	if C > 180 {
		C = 360 - C
		// Adjusting the angle C if it is greater than 180 degrees
	}

	cosC := math.Cos(math.Radians(C))
	// Calculating the cosine of angle C in radians

	fmt.Println(math.Sqrt(float64(a*a + b*b - 2*a*b*cosC)))
	// Printing the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines
}


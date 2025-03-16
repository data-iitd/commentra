package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Read input values for hours (h), minutes (m), and lengths (a, b)
	input := strings.Split(fmt.Sscanln(), " ")
	a, _ := strconv.Atoi(input[0])
	b, _ := strconv.Atoi(input[1])
	h, _ := strconv.Atoi(input[2])
	m, _ := strconv.Atoi(input[3])

	// Calculate the angle C between the hour and minute hands of the clock
	// The formula calculates the absolute difference in degrees
	C := math.Abs(360/60*float64(m) - 360/12*float64(h) - 360/12/60*float64(m))

	// If the angle is greater than 180 degrees, find the smaller angle
	if C > 180 {
		C = 360 - C
	}

	// Calculate the cosine of angle C in radians
	cosC := math.Cos(math.Radians(C))

	// Use the Law of Cosines to calculate the length of the third side of the triangle
	// formed by the lengths a, b, and the angle C
	fmt.Println(math.Sqrt(math.Pow(float64(a), 2) + math.Pow(float64(b), 2) - 2*float64(a)*float64(b)*cosC))
}


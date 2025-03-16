package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Assign values to variables a, b, h, and m using the input function and map function
	a, b, h, m := mapInt(input())

	// Calculate the angle C between hour hand and minute hand
	C := abs(360/60*m-360/12*h-360/12/60*m)
	if C > 180 {
		// If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
		C = 360 - C
	}

	// Calculate the cosine of angle C
	cosC := math.Cos(math.Radians(C))

	// Calculate and print the length of the side of the right triangle formed by the hour and minute hands
	fmt.Println(math.Sqrt(a*a + b*b - 2*a*b*cosC))
}

func mapInt(s string) (int, int, int, int) {
	// Split the input string into a slice of strings
	ss := strings.Split(s, " ")

	// Convert each string in the slice to an integer
	a, _ := strconv.Atoi(ss[0])
	b, _ := strconv.Atoi(ss[1])
	h, _ := strconv.Atoi(ss[2])
	m, _ := strconv.Atoi(ss[3])

	return a, b, h, m
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

// 
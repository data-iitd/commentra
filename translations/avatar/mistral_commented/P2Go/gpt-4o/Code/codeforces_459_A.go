package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Get user input
	var input string
	fmt.Scanln(&input)

	// Split the input into a slice of strings and convert to integers
	l1 := strings.Split(input, " ")
	var points []int
	for _, s := range l1 {
		num, _ := strconv.Atoi(s)
		points = append(points, num)
	}

	// Assign the first two elements of the slice to x1, y1 and the last two elements to x2, y2
	x1, y1 := points[0], points[1]
	x2, y2 := points[2], points[3]

	// Calculate the denominator and numerator of the slope
	denominator := x2 - x1
	numerator := y2 - y1

	// Check if the denominator is zero
	if denominator == 0 {
		// Calculate the distance between the two points and print the result
		d := int(math.Sqrt(float64((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))))
		x4, x3, y3, y4 := x1, x2, y2+d, y1+d
		fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)

	} else {
		// Calculate the quotient
		quotient := float64(numerator) / float64(denominator)

		// Check if the quotient is equal to 1 or -1
		if quotient == 1 || quotient == -1 {
			var x3, y3, x4, y4 int
			if quotient == 1 {
				x4, x3, y3, y4 = x2, x1, y1, y2
			} else {
				x4, x3, y3, y4 = x1, x2, y2, y1
			}
			fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
		} else {
			// If the quotient is not 1 or -1, print -1
			fmt.Println("-1")
		}
	}
}

// <END-OF-CODE>

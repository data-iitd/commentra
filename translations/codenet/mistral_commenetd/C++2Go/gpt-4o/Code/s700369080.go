package main

import (
	"fmt"
)

func main() {
	// Define variables to store input coordinates
	var x1, y1, x2, y2 int64

	// Read input coordinates from standard input
	fmt.Scan(&x1, &y1, &x2, &y2)

	// Calculate differences between final and initial coordinates
	dx := x2 - x1
	dy := y2 - y1

	// Calculate coordinates of points to the left and above, and right and below the final point
	x3 := x2 - dy
	y3 := y2 + dx
	x4 := x1 - dy
	y4 := y1 + dx

	// Print the calculated coordinates to the standard output
	fmt.Println(x3, y3, x4, y4)
}

// <END-OF-CODE>

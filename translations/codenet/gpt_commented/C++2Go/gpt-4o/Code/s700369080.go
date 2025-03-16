package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold the coordinates of two points
	var x1, y1, x2, y2 int64

	// Input the coordinates of the two points from the user
	fmt.Scan(&x1, &y1, &x2, &y2)

	// Calculate the differences in x and y coordinates
	dx := x2 - x1 // Difference in x-coordinates
	dy := y2 - y1 // Difference in y-coordinates

	// Calculate the coordinates of the two new points that form a rectangle
	x3 := x2 - dy // x-coordinate of the third point
	y3 := y2 + dx // y-coordinate of the third point
	x4 := x1 - dy // x-coordinate of the fourth point
	y4 := y1 + dx // y-coordinate of the fourth point

	// Output the coordinates of the two new points
	fmt.Println(x3, y3, x4, y4)
}

// <END-OF-CODE>

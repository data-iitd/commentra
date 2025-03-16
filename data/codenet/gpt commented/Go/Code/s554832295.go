package main

import "fmt"

func main() {
    // Declare variables to hold the coordinates of two points
	var x1, y1, x2, y2 int
    
    // Read the coordinates of the two points from standard input
	fmt.Scan(&x1, &y1, &x2, &y2)

    // Calculate the differences in x and y coordinates
	a := x2 - x1 // Difference in x-coordinates
	b := y2 - y1 // Difference in y-coordinates

    // Calculate the coordinates of the two new points that form a rectangle
	x3 := x2 - b // x-coordinate of the third point
	y3 := y2 + a // y-coordinate of the third point
	x4 := x1 - b // x-coordinate of the fourth point
	y4 := y1 + a // y-coordinate of the fourth point

    // Output the coordinates of the two new points
	fmt.Println(x3, y3, x4, y4)
}

package main

import (
	"fmt"
	"math"
)

func main() {
	var x1, y1, x2, y2 int
	// Read the coordinates of the two points (x1, y1) and (x2, y2)
	fmt.Scan(&x1, &y1, &x2, &y2)

	// Check if the two points are vertically aligned (same x-coordinate)
	if x1 == x2 {
		// Calculate the vertical distance between the two points
		dif := int(math.Abs(float64(y1 - y2)))
		// Output the coordinates of the rectangle formed by the two points
		fmt.Printf("%d %d %d %d\n", x1+dif, y1, x1+dif, y2)
	} else if y1 == y2 { // Check if the two points are horizontally aligned (same y-coordinate)
		// Calculate the horizontal distance between the two points
		dif := int(math.Abs(float64(x1 - x2)))
		// Output the coordinates of the rectangle formed by the two points
		fmt.Printf("%d %d %d %d\n", x1, y1+dif, x2, y2+dif)
	} else if int(math.Abs(float64(x1-x2))) == int(math.Abs(float64(y1-y2))) { // Check if the two points form a square
		// Output the coordinates of the rectangle formed by swapping y-coordinates
		fmt.Printf("%d %d %d %d\n", x1, y2, x2, y1)
	} else { // If none of the above conditions are met
		fmt.Println(-1)
	}
}

// <END-OF-CODE>

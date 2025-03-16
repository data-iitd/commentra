package main

import (
	"fmt"
)

func main() {
	// Declare variables for width (W), height (H), circle center coordinates (x, y), and radius (r)
	var W, H, x, y, r int

	// Read input values for width, height, circle center coordinates, and radius
	fmt.Scan(&W, &H, &x, &y, &r)

	// Check if the circle is out of bounds on any side
	if x - r < 0 || x + r > W || y - r < 0 || y + r > H {
		// If the circle exceeds the boundaries, print "No"
		fmt.Println("No")
	} else if x - r >= 0 && x + r <= W && y - r >= 0 && y + r <= H {
		// If the circle is completely within the boundaries, print "Yes"
		fmt.Println("Yes")
	}
}


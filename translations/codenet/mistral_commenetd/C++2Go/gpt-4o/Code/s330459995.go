package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var W, H, x, y, r int

	// Read input values from user
	fmt.Scan(&W, &H, &x, &y, &r)

	// Check if point is inside the rectangle or not
	if x-r < 0 || x+r > W || y-r < 0 || y+r > H {
		// If point is outside the rectangle
		fmt.Println("No")
	} else if x-r >= 0 && x+r <= W && y-r >= 0 && y+r <= H {
		// If point is inside the rectangle
		fmt.Println("Yes")
	}

	// Return 0 to indicate successful execution of the program
}

// <END-OF-CODE>

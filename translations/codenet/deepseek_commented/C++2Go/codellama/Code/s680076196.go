package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c, d int // Declare variables to store the input values
	fmt.Scan(&a, &b, &c, &d) // Read the four integer values from the user

	// Perform calculations
	area := (a - c) * (b - d) // Calculate the area of the rectangle using the given coordinates

	// Output the result
	fmt.Println(area) // Print the calculated area to the console
}


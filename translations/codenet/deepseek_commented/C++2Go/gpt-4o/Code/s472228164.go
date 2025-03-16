package main

import (
	"fmt"
)

// Function to check if a certain condition is met based on the values of x and y
func check(x int, y int) string {
	// Check if y is even
	if y%2 == 0 {
		// Calculate t as half of y minus x
		t := (y / 2) - x
		// Check if t is non-negative and x minus t is also non-negative
		if t >= 0 && (x-t) >= 0 {
			return "Yes"
		}
	}
	// If the conditions are not met, return "No"
	return "No"
}

func main() {
	var x, y int
	// Read two integers x and y from the standard input
	fmt.Scan(&x, &y)

	// Call the check function with x and y, and print the result
	fmt.Println(check(x, y))
}

// <END-OF-CODE>

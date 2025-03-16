package main

import (
	"fmt"
	"math"
)

// Function to calculate the absolute value of a number
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	// Declare variables
	var N, t, x, y, nx, ny, nt int

	// Read the number of test cases
	fmt.Scan(&N)
	
	// Loop through each test case
	for i := 0; i < N; i++ {
		// Read the time and coordinates for each test case
		fmt.Scan(&t, &x, &y)
		
		// Calculate the time left after accounting for the previous time and the distance traveled
		tmp := t - nt - (abs(x - nx) + abs(y - ny))
		
		// Check if the remaining time is negative or odd
		if tmp < 0 || tmp % 2 != 0 {
			// If so, print "No" and exit the program
			fmt.Println("No")
			return
		}
		
		// Update the current position and time for the next iteration
		nt = t // Update the previous time
		nx = x // Update the previous x coordinate
		ny = y // Update the previous y coordinate
	}
	
	// If all test cases are valid, print "Yes"
	fmt.Println("Yes")
}


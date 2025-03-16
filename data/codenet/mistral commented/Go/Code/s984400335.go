// Package declaration
package main

import (
	// Importing the 'fmt' package for input/output operations
	"fmt"
)

// Function declaration for finding the minimum number among given integers
func min(nums ...int) int {
	// Initializing the minimum value with the first integer
	min := nums[0]

	// Iterating through the slice 'nums' to find the minimum value
	for _, v := range nums {
		// If the current value is less than the minimum value, update the minimum value
		if v < min {
			min = v
		}
	}

	// Returning the minimum value
	return min
}

// Main function declaration
func main() {
	// Declaring three integer variables for reading input values
	var n, a, b int

	// Reading input values from the standard input using 'fmt.Scan' function
	fmt.Scan(&n, &a, &b)

	// Printing the minimum value between 'n*a' and 'b' using 'fmt.Println' function
	fmt.Println(min(n*a, b))
}

// End of the code

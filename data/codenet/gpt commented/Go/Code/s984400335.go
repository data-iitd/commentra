package main

import (
	"fmt"
)

// min function takes a variable number of integer arguments and returns the minimum value among them.
func min(nums ...int) int {
	// Initialize min with the first element of nums
	min := nums[0]
	// Iterate over each value in nums to find the minimum
	for _, v := range nums {
		// Update min if the current value is less than the current min
		if v < min {
			min = v
		}
	}
	// Return the minimum value found
	return min
}

func main() {
	// Declare variables to hold input values
	var n, a, b int
	// Read three integers from standard input
	fmt.Scan(&n, &a, &b)

	// Calculate the minimum of n*a and b, and print the result
	fmt.Println(min(n*a, b))
}

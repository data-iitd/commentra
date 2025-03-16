package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the console
	var scan = new(Scanner)

	// Read the number of test cases from user input
	var n int
	fmt.Scan(&n)

	// Loop through each test case
	for i := 0; i < n; i++ {
		// Read two integers a and b from user input
		var a, b int
		fmt.Scan(&a, &b)

		// Call the sub method and print the result
		fmt.Println(sub(a, b))
	}
}

// Method to perform a specific subtraction-like operation
func sub(a, b int) int {
	// Determine the minimum and maximum of the two numbers
	min := math.Min(float64(a), float64(b))
	max := math.Max(float64(a), float64(b))

	// Initialize the result variable to store the final output
	result := 0

	// Continue the process while min is greater than 0
	for min > 0 {
		// Add the quotient of max divided by min to the result
		result += int(max / min)

		// Update max to be the remainder of max divided by min
		max = max % min

		// Update min and max for the next iteration
		curr_min := math.Min(float64(min), float64(max))
		curr_max := math.Max(float64(min), float64(max))
		min = int(curr_min)
		max = int(curr_max)
	}

	// Return the final result
	return result
}

// 
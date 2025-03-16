package main

import (
	"fmt"
)

func main() {
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
	min := a
	max := b
	if a > b {
		min = b
		max = a
	}

	// Initialize the result variable to store the final output
	result := 0

	// Continue the process while min is greater than 0
	for min > 0 {
		// Add the quotient of max divided by min to the result
		result += max / min

		// Update max to be the remainder of max divided by min
		max = max % min

		// Update min and max for the next iteration
		currMin := min
		currMax := max
		if max < min {
			currMin = max
			currMax = min
		}
		min = currMin
		max = currMax
	}

	// Return the final result
	return result
}

// <END-OF-CODE>

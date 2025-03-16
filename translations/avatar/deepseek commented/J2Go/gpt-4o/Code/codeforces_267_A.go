package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the user
	var n int
	// Read an integer value n from the user and store it in the variable n
	fmt.Scan(&n)

	// Loop n times to read pairs of integers and print their greatest common divisor
	for i := 0; i < n; i++ {
		var a, b int
		// Read two integers a and b from the user and store them in the variables a and b
		fmt.Scan(&a, &b)

		// Call the sub method with the values of a and b as arguments and print the result
		fmt.Println(sub(a, b))
	}
}

// Define the sub method to calculate the greatest common divisor using the Euclidean algorithm
func sub(a, b int) int {
	// Initialize min and max to store the smaller and larger of the two input values
	min := a
	max := b
	if a > b {
		min = b
		max = a
	}

	// Initialize result to 0, which will be used to store the result of the Euclidean algorithm
	result := 0

	// Apply the Euclidean algorithm until min becomes 0
	for min > 0 {
		// Add the quotient of max divided by min to result
		result += max / min

		// Update max to be the remainder of max divided by min
		max = max % min

		// Swap min and max if necessary to ensure min is the smaller value
		currMin := min
		currMax := max
		if min > max {
			currMin = max
			currMax = min
		}
		min = currMin
		max = currMax
	}

	// Return the value of result, which represents the greatest common divisor
	return result
}

// <END-OF-CODE>

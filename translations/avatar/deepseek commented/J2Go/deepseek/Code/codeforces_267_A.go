package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a new Scanner object to read input from the user
	var n int
	fmt.Scan(&n)
	
	// Loop n times to read pairs of integers and print their greatest common divisor
	for i := 0; i < n; i++ {
		// Read two integers a and b from the user and store them in the variables a and b
		var a, b int
		fmt.Scan(&a, &b)
		
		// Call the sub method with the values of a and b as arguments and print the result
		fmt.Println(sub(a, b))
	}
}

// Define the sub method to calculate the greatest common divisor using the Euclidean algorithm
func sub(a, b int) int {
	// Initialize min and max to store the smaller and larger of the two input values
	min := int(math.Min(float64(a), float64(b)))
	max := int(math.Max(float64(a), float64(b)))
	
	// Initialize result to 0, which will be used to store the result of the Euclidean algorithm
	result := 0
	
	// Apply the Euclidean algorithm until min becomes 0
	for min > 0 {
		// Add the quotient of max divided by min to result
		result += max / min
		
		// Update max to be the remainder of max divided by min
		max = max % min
		
		// Swap min and max if necessary to ensure min is the smaller value
		if min > max {
			min, max = max, min
		}
	}
	
	// Return the value of result, which represents the greatest common divisor
	return result
}


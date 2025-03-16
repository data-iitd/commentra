package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
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
	if b < a {
		min = b
	}
	max := a
	if b > a {
		max = b
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
		curr_min := min
		if max < min {
			curr_min = max
		}
		curr_max := max
		if min < max {
			curr_max = min
		}
		min = curr_min
		max = curr_max
	}
	
	// Return the final result
	return result
}

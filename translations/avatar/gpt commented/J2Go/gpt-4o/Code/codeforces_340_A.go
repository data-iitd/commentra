package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the user
	var x, y, a, b int64

	// Read four long integer inputs from the user
	fmt.Scan(&x, &y, &a, &b)

	// Initialize variables for calculations
	j := int64(2)
	var c int64
	ans := true // Flag to check if a valid solution exists

	// Determine the maximum of x and y
	c = max(x, y)

	// Check if the maximum value exceeds the upper bound b
	if c > b {
		fmt.Println("0") // Output 0 if no valid multiples exist
		ans = false      // Set answer flag to false
	}

	// Loop to find the least common multiple (LCM) of x and y
	for c%min(x, y) != 0 && ans {
		// Multiply by j to find the next multiple
		if x > y {
			c = x * j // Calculate next multiple of x
			j++
		} else {
			c = y * j // Calculate next multiple of y
			j++
		}

		// Check if the calculated multiple exceeds the upper bound b
		if c > b {
			fmt.Println("0") // Output 0 if no valid multiples exist
			ans = false      // Set answer flag to false
			break            // Exit the loop
		}
	}

	// If a valid multiple was found within the bounds
	if ans {
		count := int64(0) // Initialize count of valid multiples
		// Find the first multiple of c within the range [a, b]
		for i := a; i <= b; i++ {
			if i%c == 0 {
				break // Break when a multiple is found
			}
		}

		// Check if a valid multiple was found within the range
		if i != b+1 {
			// Calculate the number of multiples of c in the range [a, b]
			fmt.Println(((b - i) / c) + 1)
		} else {
			fmt.Println("0") // Output 0 if no multiples found
		}
	}
}

// Helper function to find the minimum of two int64 values
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// Helper function to find the maximum of two int64 values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

package main

import (
	"fmt"
	"sort"
)

func main() {
	// Initialize a slice to hold the input values
	a := make([]int, 5)
	// Create a map to store the required values for adjustment
	mapAdjustments := make(map[int]int)

	// Read 5 integers from the user and calculate their remainders
	for i := 0; i < len(a); i++ {
		fmt.Scan(&a[i]) // Read input value
		r := a[i] % 10 // Calculate remainder when divided by 10

		// Initialize adjustment value
		b := 10
		// If the remainder is not zero, calculate the adjustment needed to make it a multiple of 10
		if r != 0 {
			b = 10 - r
			// Store the adjustment and the original value in the map
			mapAdjustments[b] = a[i]
		}
	}

	// Initialize the answer variable to accumulate the result
	ans := 0

	// If no adjustments are needed (map is empty), sum all input values
	if len(mapAdjustments) == 0 {
		for i := 0; i < len(a); i++ {
			ans += a[i] // Add all values to the answer
		}
		fmt.Println(ans) // Print the result
		return          // Exit the program
	}

	// Get the last key (largest adjustment) from the map
	var last int
	var maxKey int
	for k := range mapAdjustments {
		if k > maxKey {
			maxKey = k
			last = mapAdjustments[k]
		}
	}

	var idx int

	// Find the index of the last value in the original array
	for i := 0; i < len(a); i++ {
		if a[i] == last {
			idx = i // Store the index of the last value
			break
		}
	}

	// Calculate the final answer by adding values, adjusting as necessary
	for i := 0; i < len(a); i++ {
		if i != idx { // Skip the last value
			if a[i]%10 == 0 {
				ans += a[i] // If already a multiple of 10, add directly
			} else {
				r := a[i] % 10
				ans += a[i] + (10 - r) // Adjust to the next multiple of 10
			}
		}
	}

	// Add the last value to the answer
	ans += last

	// Print the final calculated answer
	fmt.Println(ans)
}

// <END-OF-CODE>

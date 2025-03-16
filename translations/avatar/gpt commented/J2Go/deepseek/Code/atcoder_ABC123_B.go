package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a map to read input values and their remainders
	var a [5]int
	var r [5]int
	
	// Create a map to store the required values for adjustment
	mapa := make(map[int]int)
	
	// Read 5 integers from the user and calculate their remainders
	for i := 0; i < 5; i++ {
		fmt.Scan(&a[i]) // Read input value
		r[i] = a[i] % 10 // Calculate remainder when divided by 10
		
		// Initialize adjustment value
		b := 10
		// If the remainder is not zero, calculate the adjustment needed to make it a multiple of 10
		if r[i] != 0 {
			b = 10 - r[i]
			// Store the adjustment and the original value in the map
			mapa[b] = a[i]
		}
	}
	
	// Initialize the answer variable to accumulate the result
	var ans int
	
	// If no adjustments are needed (map is empty), sum all input values
	if len(mapa) == 0 {
		for i := 0; i < 5; i++ {
			ans += a[i] // Add all values to the answer
		}
		fmt.Println(ans) // Print the result
		return // Exit the program
	}
	
	// Get the last key (largest adjustment) from the map
	keys := make([]int, 0, len(mapa))
	for k := range mapa {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	last := mapa[keys[len(keys)-1]]
	var idx int
	
	// Find the index of the last value in the original array
	for i := 0; i < 5; i++ {
		if a[i] == last {
			idx = i // Store the index of the last value
		}
	}
	
	// Calculate the final answer by adding values, adjusting as necessary
	for i := 0; i < 5; i++ {
		if i != idx { // Skip the last value
			if a[i] % 10 == 0 {
				ans += a[i] // If already a multiple of 10, add directly
			} else {
				ans += a[i] + (10 - r[i]) // Adjust to the next multiple of 10
			}
		}
	}
	
	// Add the last value to the answer
	ans += last
	
	// Print the final calculated answer
	fmt.Println(ans)
}

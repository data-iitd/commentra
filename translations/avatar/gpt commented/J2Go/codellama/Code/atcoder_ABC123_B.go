package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := new(Scanner)

	// Initialize two arrays to hold the input values and their remainders
	a := make([]int, 5)
	r := make([]int, 5)

	// Create a TreeMap to store the required values for adjustment
	map := make(map[int]int)

	// Read 5 integers from the user and calculate their remainders
	for i := 0; i < len(a); i++ {
		a[i] = sc.NextInt() // Read input value
		r[i] = a[i] % 10     // Calculate remainder when divided by 10

		// Initialize adjustment value
		b := 10
		// If the remainder is not zero, calculate the adjustment needed to make it a multiple of 10
		if r[i] != 0 {
			b = 10 - r[i]
			// Store the adjustment and the original value in the TreeMap
			map[b] = a[i]
		}
	}

	// Initialize the answer variable to accumulate the result
	ans := 0

	// If no adjustments are needed (map is empty), sum all input values
	if len(map) == 0 {
		for i := 0; i < len(a); i++ {
			ans += a[i] // Add all values to the answer
		}
		fmt.Println(ans) // Print the result
		return           // Exit the program
	}

	// Get the last key (largest adjustment) from the TreeMap
	last := map[map.LastKey()]
	idx := 0

	// Find the index of the last value in the original array
	for i := 0; i < len(a); i++ {
		if a[i] == last {
			idx = i // Store the index of the last value
		}
	}

	// Calculate the final answer by adding values, adjusting as necessary
	for i := 0; i < len(a); i++ {
		if i != idx { // Skip the last value
			if a[i]%10 == 0 {
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

// END-OF-CODE

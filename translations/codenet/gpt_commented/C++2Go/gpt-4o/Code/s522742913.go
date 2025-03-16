package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Declare a string variable to hold the input
	var source string
	// Read input from the user
	fmt.Scan(&source)

	// Check if the input length is valid (between 1 and 10 characters)
	if len(source) > 10 || len(source) < 1 {
		// Return -1 if the input length is invalid
		return
	}

	// Calculate the maximum number of combinations of '+' placements
	maxI := int(math.Pow(2, float64(len(source)-1)))

	// Initialize a variable to hold the cumulative sum of the evaluated expressions
	var sum float64

	// Iterate through all possible combinations of '+' placements
	for i := 0; i < maxI; i++ {
		// Initialize a variable to hold the current number being evaluated
		var number float64

		// Create a working copy of the source string to manipulate
		working := source
		// Create a bitmask for the current combination of '+' placements
		bitmask := fmt.Sprintf("%0*b", len(source)-1, i)

		// While there are still '+' placements to evaluate
		for j := 0; j < len(bitmask); j++ {
			// If the current bit is '1', we need to split the string
			if bitmask[j] == '1' {
				// Convert the substring up to the current position to a float and add to sum
				num, _ := strconv.ParseFloat(working[:j+1], 64)
				sum += num
				// Update the working string to remove the processed segment
				working = working[j+1:]
				// Reset j to -1 to account for the increment in the for loop
				j = -1
			}
		}
		// Add the remaining part of the working string to the sum
		if len(working) > 0 {
			num, _ := strconv.ParseFloat(working, 64)
			sum += num
		}
	}

	// Print the final sum
	fmt.Printf("%.0f\n", sum)
}

// <END-OF-CODE>

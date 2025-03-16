package main

import (
	"fmt"
	"math"
	"strconv"
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
	max_i := int(math.Pow(2, float64(len(source)-1)))

	// Initialize a variable to hold the cumulative sum of the evaluated expressions
	var sum float64

	// Iterate through all possible combinations of '+' placements
	for i := 0; i < max_i; i++ {
		// Create a bitset to represent the current combination of '+' placements
		plus := strconv.FormatInt(int64(i), 2)

		// Initialize a variable to hold the current number being evaluated
		var number float64

		// Create a working copy of the source string to manipulate
		working := source
		// While there are still '+' placements to evaluate
		for len(plus) > 0 {
			// Find the next position of a '1' in the bitset
			for i := 0; i < len(plus); i++ {
				if plus[i] == '1' {
					// Convert the substring up to the current position to a float64 and add to sum
					number, _ = strconv.ParseFloat(working[:i+1], 64)
					sum += number
					// Update the working string to remove the processed segment
					working = working[i+1:]
					// Remove the processed segment from the bitset
					plus = plus[i+1:]
					break
				}
			}
		}
		// Add the remaining part of the working string to the sum
		number, _ = strconv.ParseFloat(working, 64)
		sum += number
	}

	// Set the precision for output and print the final sum
	fmt.Printf("%.0f\n", sum)
}


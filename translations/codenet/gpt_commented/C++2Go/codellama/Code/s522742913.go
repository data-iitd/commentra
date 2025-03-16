package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Declare a string variable to hold the input
	source := ""
	// Read input from the user
	fmt.Scan(&source)

	// Check if the input length is valid (between 1 and 10 characters)
	if len(source) > 10 || len(source) < 1 {
		// Return -1 if the input length is invalid
		fmt.Println(-1)
		return
	}

	// Calculate the maximum number of combinations of '+' placements
	max_i := int(math.Pow(2, float64(len(source)-1)))

	// Initialize a variable to hold the cumulative sum of the evaluated expressions
	sum := 0.0

	// Iterate through all possible combinations of '+' placements
	for i := 0; i < max_i; i++ {
		// Create a bitset to represent the current combination of '+' placements
		plus := strings.Repeat("0", len(source)-1)
		plus = plus[:len(source)-1]
		plus = plus[:i] + "1" + plus[i:]

		// Initialize a variable to hold the current number being evaluated
		number := 0.0

		// Create a working copy of the source string to manipulate
		working := source
		// While there are still '+' placements to evaluate
		for plus != "" {
			// Find the next position of a '1' in the bitset
			i := strings.Index(plus, "1")
			// Convert the substring up to the current position to a double and add to sum
			number += atof(working[:i+1])
			// Shift the bitset to the right to evaluate the next segment
			plus = plus[i+1:]
			// Update the working string to remove the processed segment
			working = working[i+1:]
		}
		// Add the remaining part of the working string to the sum
		number += atof(working)
		sum += number
	}

	// Set the precision for output and print the final sum
	fmt.Printf("%.0f\n", sum)
}

func atof(s string) float64 {
	f, _ := strconv.ParseFloat(s, 64)
	return f
}


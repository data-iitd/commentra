package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Initialize an empty string variable named 'source'
	var source string

	// Read a string input from the standard input stream (os.Stdin) and store it in the 'source' variable
	fmt.Scan(&source)

	// Check if the length of the input string is valid (greater than 10 characters or less than 1 character)
	if len(source) > 10 || len(source) < 1 {
		// If the condition is true, return an error code (-1)
		return
	}

	// Calculate the maximum value of 'i' based on the length of the input string using bitwise operations
	maxI := int(math.Pow(2, float64(len(source)-1)))

	// Initialize a variable named 'sum' with a value of 0
	var sum float64 = 0

	// Iterate through the range of 'i' from 0 to 'maxI' using a for loop
	for i := 0; i < maxI; i++ {
		// Create a bit representation of 'i'
		plus := fmt.Sprintf("%b", i)
		plus = fmt.Sprintf("%0*s", len(source)-1, plus) // Pad with leading zeros

		// Initialize a variable named 'number' with a value of 0
		number := 0.0

		// Initialize a string variable named 'working' with the value of the input string 'source'
		working := source

		// Iterate through the bits of the 'plus' string
		for j := 0; j < len(plus); j++ {
			if plus[j] == '1' {
				// Add the substring of the 'working' string starting from the first '1' bit index to the 'sum' variable
				substring := working[:j+1]
				value, _ := strconv.ParseFloat(substring, 64)
				sum += value

				// Update the value of the 'working' string by removing the substring that has been added to the 'sum' variable
				working = working[j+1:]
			}
		}

		// Add the remaining substring of the 'working' string to the 'sum' variable
		if len(working) > 0 {
			value, _ := strconv.ParseFloat(working, 64)
			sum += value
		}
	}

	// Print the value of the 'sum' variable to the standard output stream (fmt) with no decimal places
	fmt.Printf("%.0f\n", sum)
}

// <END-OF-CODE>

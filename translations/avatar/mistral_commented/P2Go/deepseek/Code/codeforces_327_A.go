package main

import (
	"fmt"
	"strings"
)

// Define a helper function 'find' to locate the indices of a character in a string
func find(s string, ch byte) []int {
	// Use a slice to store the indices where the character 'ch' appears in the string 's'
	var indices []int
	// Iterate through the string 's' and append the index of 'ch' to the slice
	for i := 0; i < len(s); i++ {
		if s[i] == ch {
			indices = append(indices, i)
		}
	}
	return indices
}

func main() {
	// Read the number of test cases 'n' from the standard input
	var n int
	fmt.Scan(&n)

	// Read the string 's' from the standard input and remove any leading or trailing whitespaces
	var s string
	fmt.Scan(&s)
	s = strings.ReplaceAll(s, " ", "")

	// Check if the string 's' does not contain '0' character
	if !strings.Contains(s, "0") {
		// If '0' is not present, print the result as the number of test cases minus one
		fmt.Println(n - 1)
	} else {
		// Find the indices of '0' character in the string 's'
		indices := find(s, '0')

		// Check if there is only one '0' character in the string 's'
		if len(indices) == 1 {
			// If there is only one '0', print the result as the number of '1's in the string
			fmt.Println(n)
		} else {
			// Initialize the maximum combination score as 0
			maximum := 0

			// Generate all possible combinations of indices of '0' characters
			for i := 0; i < len(indices); i++ {
				for j := i + 1; j < len(indices); j++ {
					// Calculate the score for the current combination using the given formula
					score := 2 + 2*(abs(indices[i]-indices[j])-1) - (abs(indices[i]-indices[j]) - 1)
					// Update the maximum combination score if the current combination score is greater
					if score > maximum {
						maximum = score
					}
				}
			}

			// Print the final result which is the number of '1's in the string plus the maximum combination score
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}

// Define a function 'abs' to calculate the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

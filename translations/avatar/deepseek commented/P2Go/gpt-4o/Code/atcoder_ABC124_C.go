package main

import (
	"fmt"
)

func main() {
	// Take a string input from the user and store it in the variable `s`
	var s string
	fmt.Scan(&s)

	// Create maps to count occurrences of characters at even and odd indices
	even := make(map[rune]int)
	odd := make(map[rune]int)

	// Count occurrences of characters at even and odd indices
	for i, char := range s {
		if i%2 == 0 {
			even[char]++
		} else {
			odd[char]++
		}
	}

	// Calculate the number of flips needed for both scenarios
	flipsToZeroEven := len(s) - (even['0'] + odd['1'])
	flipsToOneEven := len(s) - (even['1'] + odd['0'])

	// Print the minimum of the two outcomes
	fmt.Println(min(flipsToZeroEven, flipsToOneEven))
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>

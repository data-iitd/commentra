package main

import (
	"fmt"
	"strings"
)

// find returns the indices of all occurrences of the character 'ch' in the string's'
func find(s string, ch byte) []int {
	// Initialize an empty list of indices
	var indices []int

	// Iterate through each character in the string's'
	for i, ltr := range s {
		// Check if the current character is equal to the character 'ch'
		if ltr == ch {
			// If yes, append the current index to the list of indices
			indices = append(indices, i)
		}
	}

	// Return the list of indices
	return indices
}

// main function
func main() {
	// Read the number of test cases 'n' from the standard input
	var n int
	fmt.Scanf("%d", &n)

	// Read the string's' from the standard input and remove any leading or trailing whitespaces
	s := strings.Replace(strings.TrimSpace(fmt.Sscanln("")), "", "")

	// Check if the string's' does not contain '0' character
	if strings.IndexByte(s, '0') == -1 {
		// If '0' is not present, print the result as the number of test cases minus one
		fmt.Println(n - 1)
	} else {
		// If '0' is present, proceed with further logic
		// Find the indices of '0' character in the string's'
		indices := find(s, '0')

		// Check if there is only one '0' character in the string's'
		if len(indices) == 1 {
			// If there is only one '0', print the result as the number of '1's in the string
			fmt.Println(n)
		} else {
			// If there are multiple '0's, calculate the maximum combination score
			// Initialize the maximum combination score as 0
			var maximum int = 0

			// Generate all possible combinations of indices of '0' characters using itertools.combinations()
			combs := combinations(indices, 2)

			// Iterate through each combination and calculate the score for that combination
			for _, x := range combs {
				// Calculate the score for the current combination using the given formula
				score := 2 + 2*(abs(indices[x[0]]-indices[x[1]])-1) - (abs(x[0]-x[1])-1)
				// Update the maximum combination score if the current combination score is greater
				maximum = max(maximum, score)

			}

			// Print the final result which is the number of '1's in the string plus the maximum combination score
			fmt.Println(strings.Count(s, "1") + maximum)
	}
}

// combinations returns all possible combinations of 'n' elements from the list 'indices'
func combinations(indices []int, n int) [][]int {
	// Initialize an empty list of combinations
	var combs [][]int

	// Iterate through each combination using 'n' elements from the list 'indices'
	for _, x := range itertools.Combinations(indices, n) {
		// Append the current combination to the list of combinations
		combs = append(combs, x)
	}

	// Return the list of combinations
	return combs
}

// max returns the maximum of two integers
func max(a, b int) int {
	// If the first integer is greater than the second integer, return the first integer
	if a > b {
		return a
	}

	// If the first integer is less than the second integer, return the second integer
	return b
}

// END-OF-CODE

package main

import (
	"fmt"
	"strings"
)

func find(s string, ch rune) []int {
	// This function returns a slice of indices where the character 'ch' appears in the string 's'.
	var indices []int
	for i, ltr := range s {
		if ltr == ch {
			indices = append(indices, i)
		}
	}
	return indices
}

func main() {
	// Read an integer input 'n' which represents the length of the string.
	var n int
	fmt.Scan(&n)

	// Read the string input 's'.
	var s string
	fmt.Scan(&s)

	// Check if the string 's' contains the character '0'.
	if !strings.ContainsRune(s, '0') {
		// If '0' is not present, the output is n - 1.
		fmt.Println(n - 1)
	} else {
		// Find all indices of '0' in the string 's'.
		indices := find(s, '0')

		// If there is only one '0', output the length of the string 'n'.
		if len(indices) == 1 {
			fmt.Println(n)
		} else {
			// Initialize a variable to keep track of the maximum value found.
			maximum := 0

			// Iterate through each combination of indices.
			for i := 0; i < len(indices); i++ {
				for j := i + 1; j < len(indices); j++ {
					x0 := indices[i]
					x1 := indices[j]
					// Calculate the maximum value based on the distance between the two indices.
					maximum = max(maximum, 2+2*(abs(i-j)-1)-(abs(x0-x1)-1))
				}
			}

			// Output the count of '1's in the string plus the maximum value calculated.
			countOfOnes := strings.Count(s, "1")
			fmt.Println(countOfOnes + maximum)
		}
	}
}

// Helper function to calculate the absolute value.
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to find the maximum of two integers.
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>

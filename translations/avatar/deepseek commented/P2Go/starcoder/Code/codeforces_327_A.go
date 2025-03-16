package main

import (
	"fmt"
	"strings"
)

// Function to find indices of a character in a string
func find(s string, ch byte) []int {
	var indices []int
	for i, ltr := range s {
		if ltr == ch {
			indices = append(indices, i)
		}
	}
	return indices
}

func main() {
	// Read the integer input
	var n int
	fmt.Scanf("%d", &n)

	// Read the string input and remove spaces
	s := strings.Replace(fmt.Scanf("%s", &s), " ", "", -1)

	// If the string does not contain '0', print n - 1
	if strings.Index(s, "0") == -1 {
		fmt.Println(n - 1)
	} else {
		// Find all indices of '0' in the string
		indices := find(s, '0')

		// If there is only one '0', print n
		if len(indices) == 1 {
			fmt.Println(n)
		} else {
			// Initialize maximum to 0
			var maximum int = 0
			// Generate all combinations of two indices of '0'
			combs := make([][]int, len(indices)-1)
			for i := 0; i < len(indices)-1; i++ {
				combs[i] = []int{indices[i], indices[i+1]}
			}

			// Iterate over each combination and calculate the maximum distance
			for _, x := range combs {
				maximum = max(maximum, 2 + 2 * (abs(indices.index(x[0]) - indices.index(x[1])) - 1) - (abs(x[0] - x[1]) - 1))

			}

			// Print the count of '1's plus the maximum distance
			fmt.Println(strings.Count(s, "1") + maximum)
	}
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Function to find the absolute value of an integer
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}


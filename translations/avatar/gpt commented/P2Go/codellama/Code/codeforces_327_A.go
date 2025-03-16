package main

import (
	"fmt"
	"strings"
)

func find(s string, ch byte) []int {
	// This function returns a list of indices where the character 'ch' appears in the string 's'.
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

	// Read the string input 's' and replace any empty string occurrences (this line seems to be incorrect).
	var s string
	fmt.Scan(&s)
	s = strings.Replace(s, "", "", -1)

	// Check if the string 's' contains the character '0'.
	if !strings.Contains(s, "0") {
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
			var maximum int

			// Generate all combinations of indices of '0' taken 2 at a time.
			combs := combinations(indices, 2)

			// Iterate through each combination of indices.
			for _, x := range combs {
				// Calculate the maximum value based on the distance between the two indices.
				maximum = max(maximum, 2+2*(abs(indices[x[0]]-indices[x[1]])-1)-(abs(x[0]-x[1])-1))
			}

			// Output the count of '1's in the string plus the maximum value calculated.
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}

func combinations(s []int, r int) [][]int {
	// This function generates all combinations of 'r' elements taken from the input slice 's'.
	var combs [][]int
	n := len(s)
	if r > n {
		return combs
	}
	indices := make([]int, r)
	for i := range indices {
		indices[i] = i
	}
	for {
		combs = append(combs, append([]int{}, indices...))
		for i := r - 1; i >= 0; i-- {
			indices[i]++
			if indices[i] != i+n-r+1 {
				break
			}
		}
		if indices[0] == n-r+1 {
			break
		}
	}
	return combs
}

func max(a, b int) int {
	// This function returns the maximum of two integers.
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	// This function returns the absolute value of an integer.
	if a < 0 {
		return -a
	}
	return a
}


package main

import (
	"fmt"
	"strings"
)

func find(s, ch string) []int {
	// This function returns a list of indices where the character 'ch' appears in the string 's'.
	indices := []int{}
	for i, ltr := range s {
		if string(ltr) == ch {
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
	s = strings.ReplaceAll(s, " ", "")
	
	// Check if the string 's' contains the character '0'.
	if !strings.Contains(s, "0") {
		// If '0' is not present, the output is n - 1.
		fmt.Println(n - 1)
	} else {
		// Find all indices of '0' in the string 's'.
		indices := find(s, "0")
		
		// If there is only one '0', output the length of the string 'n'.
		if len(indices) == 1 {
			fmt.Println(n)
		} else {
			// Initialize a variable to keep track of the maximum value found.
			maximum := 0
			
			// Generate all combinations of indices of '0' taken 2 at a time.
			for i := 0; i < len(indices); i++ {
				for j := i + 1; j < len(indices); j++ {
					// Calculate the maximum value based on the distance between the two indices.
					current := 2 + 2 * (abs(indices[i] - indices[j]) - 1) - (abs(indices[i] - indices[j]) - 1)
					if current > maximum {
						maximum = current
					}
				}
			}
			
			// Output the count of '1's in the string plus the maximum value calculated.
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

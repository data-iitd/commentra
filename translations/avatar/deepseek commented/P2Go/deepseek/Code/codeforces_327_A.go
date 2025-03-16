package main

import (
	"fmt"
	"strings"
)

// Function to find indices of a character in a string
func find(s string, ch byte) []int {
	var indices []int
	for i := 0; i < len(s); i++ {
		if s[i] == ch {
			indices = append(indices, i)
		}
	}
	return indices
}

func main() {
	// Read the integer input
	var n int
	fmt.Scan(&n)
	
	// Read the string input and remove spaces
	var s string
	fmt.Scan(&s)
	s = strings.ReplaceAll(s, " ", "")
	
	// If the string does not contain '0', print n - 1
	if !strings.Contains(s, "0") {
		fmt.Println(n - 1)
	} else {
		// Find all indices of '0' in the string
		indices := find(s, '0')
		
		// If there is only one '0', print n
		if len(indices) == 1 {
			fmt.Println(n)
		} else {
			// Initialize maximum to 0
			maximum := 0
			// Generate all combinations of two indices of '0'
			for i := 0; i < len(indices); i++ {
				for j := i + 1; j < len(indices); j++ {
					// Calculate the maximum distance
					distance := 2 + 2 * (abs(indices[i] - indices[j]) - 1) - (abs(indices[i] - indices[j]) - 1)
					if distance > maximum {
						maximum = distance
					}
				}
			}
			
			// Print the count of '1's plus the maximum distance
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}


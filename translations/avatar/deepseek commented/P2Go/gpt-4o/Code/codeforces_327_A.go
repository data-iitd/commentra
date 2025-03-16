package main

import (
	"fmt"
	"strings"
	"math"
)

// Function to find indices of a character in a string
func find(s string, ch rune) []int {
	var indices []int
	for i, ltr := range s {
		if ltr == ch {
			indices = append(indices, i)
		}
	}
	return indices
}

func main() {
	var n int
	fmt.Scan(&n)
	
	var s string
	fmt.Scan(&s)
	s = strings.ReplaceAll(s, " ", "")
	
	// If the string does not contain '0', print n - 1
	if !strings.ContainsRune(s, '0') {
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
			// Iterate over each combination of two indices of '0'
			for i := 0; i < len(indices); i++ {
				for j := i + 1; j < len(indices); j++ {
					x0 := indices[i]
					x1 := indices[j]
					distance := 2 + 2*(math.Abs(float64(i-j))-1) - (math.Abs(float64(x0-x1)) - 1)
					if distance > float64(maximum) {
						maximum = int(distance)
					}
				}
			}
			// Print the count of '1's plus the maximum distance
			countOfOnes := strings.Count(s, "1")
			fmt.Println(countOfOnes + maximum)
		}
	}
}

// <END-OF-CODE>

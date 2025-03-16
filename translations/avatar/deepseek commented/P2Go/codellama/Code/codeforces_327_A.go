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

// Main block of the code
func main() {
	// Read the integer input
	var n int
	fmt.Scan(&n)
	// Read the string input and remove spaces
	s := strings.Replace(strings.TrimSpace(fmt.Sscanf("%s", &s)), " ", "", -1)

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
			combs := combinations(indices, 2)

			// Iterate over each combination and calculate the maximum distance
			for _, x := range combs {
				maximum = max(maximum, 2+2*(abs(indices[x[0]]-indices[x[1]])-1)-(abs(x[0]-x[1])-1))
			}

			// Print the count of '1's plus the maximum distance
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}

// Function to find all combinations of a given length
func combinations(s []int, r int) [][]int {
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
			for j := i + 1; j < r; j++ {
				indices[j] = indices[j-1] + 1
			}
		}
		if indices[0] == n {
			break
		}
	}
	return combs
}

// Function to find the absolute value of a number
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Function to find the maximum of two numbers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// END-OF-CODE

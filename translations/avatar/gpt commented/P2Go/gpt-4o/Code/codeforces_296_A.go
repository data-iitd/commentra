package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read an integer input n which represents the threshold for majority
	var n int
	fmt.Scan(&n)

	// Read a line of input, split it into a slice of strings, and store it in m
	var input string
	fmt.Scan(&input)
	m := strings.Split(input, " ")

	// Initialize a variable to track if a majority element is possible
	possible := true

	// Create a map to count occurrences of each unique element
	counts := make(map[string]int)
	for _, elem := range m {
		counts[elem]++
	}

	// Iterate through each unique element in the map
	for _, count := range counts {
		// Check if the count of the current element is greater than or equal to n/2 + 1
		if count >= n/2+1 {
			// If it is, set possible to false and break the loop
			possible = false
			break
		}
	}

	// Print 'YES' if a majority element is not found, otherwise print 'NO'
	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>

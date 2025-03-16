package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input representing the threshold

	var input string
	fmt.Scan(&input) // Take a space-separated string input
	m := strings.Split(input, " ") // Split the input into a slice

	possible := true // Initialize a boolean variable to check if the condition is possible
	counts := make(map[string]int) // Create a map to count occurrences of each element

	// Count occurrences of each element in the slice
	for _, item := range m {
		counts[item]++
	}

	// Iterate over the unique elements in the map
	for _, count := range counts {
		// Check if the count of the current element is greater than or equal to n / 2 + 1
		if count >= n/2+1 {
			possible = false // Set possible to false if the condition is met
			break // Break the loop as the condition is already not possible
		}
	}

	// Print 'YES' if possible is true, otherwise print 'NO'
	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>

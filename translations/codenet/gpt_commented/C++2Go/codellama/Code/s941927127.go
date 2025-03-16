package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare a string variable to hold the input
	var W string

	// Read input string from the user
	fmt.Scan(&W)

	// Sort the characters in the string in ascending order
	sort.Slice(W, func(i, j int) bool {
		return W[i] < W[j]
	})

	// Iterate through the sorted string, checking pairs of characters
	for i := 0; i < len(W)-1; i += 2 {
		// Check if the current character is not equal to the next character
		if W[i] != W[i+1] {
			// If they are not equal, print "No" and exit the program
			fmt.Println("No")
			return
		}
	}

	// If all pairs are equal, print "Yes"
	fmt.Println("Yes")
}


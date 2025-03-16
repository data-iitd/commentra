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
	
	// Convert the string to a slice of runes for sorting
	runes := []rune(W)
	
	// Sort the characters in the string in ascending order
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})

	// Iterate through the sorted string, checking pairs of characters
	for i := 0; i < len(runes); i += 2 {
		// Check if the current character is not equal to the next character
		if i+1 >= len(runes) || runes[i] != runes[i+1] {
			// If they are not equal, print "No" and exit the program
			fmt.Println("No")
			return
		}
	}
	
	// If all pairs are equal, print "Yes"
	fmt.Println("Yes")
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)
	// Read the input string

	targ := []rune(s)
	// Convert the string to a rune slice

	mapCount := make(map[rune]int)
	// Initialize a map to store character counts

	for _, char := range targ {
		// Loop through each character in the rune slice
		mapCount[char]++
		// Increment the count for the character
	}

	ok := true
	// Initialize a boolean flag to check the conditions

	if len(mapCount) != 2 {
		ok = false
	} else {
		for _, count := range mapCount {
			// Loop through each count in the map
			if count != 2 {
				// If any character count is not 2, set ok to false
				ok = false
				break
			}
		}
	}

	if ok {
		// Check if all characters appear exactly twice and there are exactly 2 unique characters
		fmt.Println("Yes")
		// Print "Yes" if the conditions are met
	} else {
		fmt.Println("No")
		// Print "No" otherwise
	}
}

// <END-OF-CODE>

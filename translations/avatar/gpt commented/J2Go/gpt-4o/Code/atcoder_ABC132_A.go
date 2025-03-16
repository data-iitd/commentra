package main

import (
	"fmt"
)

func main() {
	// Create a map to store the frequency of each character
	charCount := make(map[rune]int)

	// Read the input string from the user
	var s string
	fmt.Scan(&s)

	// Loop through each character in the string
	for _, char := range s {
		// Increment the count for the character
		charCount[char]++
	}

	// Initialize a boolean variable to check if the conditions are met
	ok := true

	// Check if each character appears exactly twice
	if len(charCount) == 2 {
		for _, count := range charCount {
			if count != 2 {
				ok = false // Set ok to false if any character does not appear twice
				break
			}
		}
	} else {
		ok = false // Set ok to false if there are not exactly two unique characters
	}

	// Output "Yes" if conditions are satisfied, otherwise "No"
	if ok {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>

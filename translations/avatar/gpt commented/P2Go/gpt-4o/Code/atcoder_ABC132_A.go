package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take input string from the user
	var S string
	fmt.Scanln(&S)

	// Create a map to count the frequency of each character in the string
	counts := make(map[rune]int)

	// Count occurrences of each character
	for _, char := range S {
		counts[char]++
	}

	// Check if the number of unique characters is not equal to 2
	if len(counts) != 2 {
		fmt.Println("No")
		return
	}

	// Iterate over each unique character in the map
	for _, count := range counts {
		// Check if the count of the current character is not equal to 2
		if count != 2 {
			fmt.Println("No")
			return
		}
	}

	// If both conditions are satisfied, print "Yes"
	fmt.Println("Yes")
}

// <END-OF-CODE>

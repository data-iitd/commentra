package main

import (
	"fmt"
)

func main() {
	// Declare two string variables to hold the input strings
	var s, t string
	
	// Read the first string from user input
	fmt.Scan(&s)
	
	// Read the second string from user input
	fmt.Scan(&t)
	
	// Initialize a counter to keep track of matching characters
	hit := 0
	
	// Loop through the first three characters of both strings
	for i := 0; i < 3; i++ {
		// Check if the characters at the same position in both strings match
		if s[i] == t[i] {
			hit++ // Increment the hit counter if there's a match
		}
	}
	
	// Output the total number of matching characters
	fmt.Println(hit)
}


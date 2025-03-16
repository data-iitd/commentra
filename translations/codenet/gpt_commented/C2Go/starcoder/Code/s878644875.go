package main

import "fmt"

func main() {
	// Declare two character arrays to hold the input strings
	var s [4]byte
	var t [4]byte

	// Read the first string from user input
	fmt.Scanf("%s", &s)

	// Read the second string from user input
	fmt.Scanf("%s", &t)

	// Initialize a counter to keep track of matching characters
	var hit int = 0

	// Loop through the first three characters of both strings
	for i := 0; i < 3; i++ {
		// Check if the characters at the same position in both strings match
		if s[i] == t[i] {
			hit++ // Increment the hit counter if there's a match
		}
	}

	// Output the total number of matching characters
	fmt.Printf("%d\n", hit)
}


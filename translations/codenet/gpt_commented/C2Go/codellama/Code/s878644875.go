package main

import "fmt"

func main() {
	// Declare two character arrays to hold the input strings
	var s [4]string
	var t [4]string

	// Read the first string from user input
	fmt.Scan(&s[0], &s[1], &s[2], &s[3])

	// Read the second string from user input
	fmt.Scan(&t[0], &t[1], &t[2], &t[3])

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

	// Return 0 to indicate successful completion of the program
	return 0
}


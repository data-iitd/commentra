package main

import (
	"fmt"
	"strings"
)

func main() {
	// Array to store the count of each letter (a-z)
	c := make([]int, 26)

	// Read input strings until there are no more inputs
	var str string
	for {
		// Read input
		if _, err := fmt.Scan(&str); err != nil {
			break
		}

		// Traverse each character in the string
		for _, ch := range str {
			// Check if the character is a lowercase letter
			if 'a' <= ch && ch <= 'z' {
				c[ch-'a']++
			} 
			// Check if the character is an uppercase letter
			if 'A' <= ch && ch <= 'Z' {
				c[ch-'A']++
			}
		}
	}

	// Print the counts for each letter from 'a' to 'z'
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

// <END-OF-CODE>

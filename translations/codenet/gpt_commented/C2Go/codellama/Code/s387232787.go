package main

import (
	"fmt"
	"os"
)

func main() {
	// Declare a string to hold the input
	var str string

	// Read strings from standard input until EOF
	for {
		// Read a string from standard input
		fmt.Scan(&str)

		// Check if the string is empty
		if str == "" {
			break
		}

		// Iterate through each character in the string
		for _, c := range str {
			// Check if the character is a lowercase letter
			if 'a' <= c && c <= 'z' {
				// Increment the count for the corresponding letter
				c[c-'a']++
			} else if 'A' <= c && c <= 'Z' {
				// Increment the count for the corresponding letter (converted to lowercase)
				c[c-'A']++
			}
		}
	}

	// Print the count of each letter from 'a' to 'z'
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}


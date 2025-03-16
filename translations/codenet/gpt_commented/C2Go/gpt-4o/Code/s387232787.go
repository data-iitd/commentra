package main

import (
	"fmt"
	"os"
)

func main() {
	// Array to hold the count of each letter (a-z)
	c := make([]int, 26)

	// Read strings from standard input until EOF
	var str string
	for {
		_, err := fmt.Scan(&str)
		if err != nil {
			break
		}

		// Iterate through each character in the string
		for _, p := range str {
			// Check if the character is a lowercase letter
			if 'a' <= p && p <= 'z' {
				// Increment the count for the corresponding letter
				c[p-'a']++
			} 
			// Check if the character is an uppercase letter
			if 'A' <= p && p <= 'Z' {
				// Increment the count for the corresponding letter (converted to lowercase)
				c[p-'A']++
			}
		}
	}

	// Print the count of each letter from 'a' to 'z'
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

// <END-OF-CODE>

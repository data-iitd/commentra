package main

import (
	"fmt"
)

func main() {
	// Array to hold the count of each letter (a-z)
	var c [26]int

	// Read strings from standard input until EOF
	for {
		// Declare a string to hold the input
		var str string
		// Read the input string
		_, err := fmt.Scan(&str)
		if err != nil {
			break
		}

		// Iterate through each character in the string
		for _, char := range str {
			// Check if the character is a lowercase letter
			if 'a' <= char && char <= 'z' {
				// Increment the count for the corresponding letter
				c[char - 'a']++
			} 
			// Check if the character is an uppercase letter
			else if 'A' <= char && char <= 'Z' {
				// Increment the count for the corresponding letter (converted to lowercase)
				c[char - 'A']++
			}
		}
	}

	// Print the count of each letter from 'a' to 'z'
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a' + i, c[i]) 
	}
}


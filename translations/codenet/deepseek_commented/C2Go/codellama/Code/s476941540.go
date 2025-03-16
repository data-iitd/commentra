package main

import (
	"fmt"
	"unicode"
)

func main() {
	var alpha [26]int
	var ch rune

	// Initialize the alpha array to zero for all elements
	for i := 0; i < 26; i++ {
		alpha[i] = 0
	}

	// Read characters from the standard input until EOF
	for {
		ch = unicode.ToLower(rune(getchar()))
		if ch == EOF {
			break
		}

		// Check if the character is an alphabetic character
		if unicode.IsLetter(ch) {
			// Increment the corresponding element in alpha based on case
			alpha[ch-'a']++
		}
	}

	// Print the counts of each letter from 'a' to 'z'
	ch = 'a'
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", ch, alpha[i])
		ch++
	}
}


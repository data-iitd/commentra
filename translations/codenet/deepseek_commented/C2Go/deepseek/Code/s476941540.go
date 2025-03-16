package main

import (
	"bufio"
	"fmt"
	"os"
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
	reader := bufio.NewReader(os.Stdin)
	for {
		ch, _, err := reader.ReadRune()
		if err != nil {
			break
		}

		// Check if the character is an alphabetic character
		if unicode.IsLetter(ch) {
			// Increment the corresponding element in alpha based on case
			if unicode.IsUpper(ch) {
				alpha[ch-'A']++
			} else {
				alpha[ch-'a']++
			}
		}
	}

	// Print the counts of each letter from 'a' to 'z'
	for i := 0; i < 26; i++ {
		ch = 'a' + rune(i)
		fmt.Printf("%c : %d\n", ch, alpha[i])
	}
}


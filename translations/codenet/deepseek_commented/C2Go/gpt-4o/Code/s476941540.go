package main

import (
	"fmt"
	"os"
	"bufio"
	"unicode"
)

func main() {
	alpha := make([]int, 26)

	// Create a buffered reader to read from standard input
	reader := bufio.NewReader(os.Stdin)

	for {
		ch, _, err := reader.ReadRune()
		if err != nil {
			break // Break on EOF or error
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
		fmt.Printf("%c : %d\n", 'a'+i, alpha[i])
	}
}

// <END-OF-CODE>

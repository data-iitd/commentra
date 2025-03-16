package main

import (
	"fmt"
	"os"
	"bufio"
	"unicode"
)

func main() {
	// Declare an array to count occurrences of each letter
	alpha := make([]int, 26)

	// Create a buffered reader to read from standard input
	reader := bufio.NewReader(os.Stdin)

	// Infinite loop to read characters until EOF (End of File) is encountered
	for {
		ch, _, err := reader.ReadRune() // Read a character from standard input
		if err != nil {
			break // Exit the loop if an error occurs (EOF)
		}

		// Check if the character is an alphabet letter
		if unicode.IsLetter(ch) {
			// If the character is uppercase, increment the corresponding index in the alpha array
			if unicode.IsUpper(ch) {
				alpha[ch-'A']++ // 'A' is at index 0, 'B' at index 1, ..., 'Z' at index 25
			} else {
				// If the character is lowercase, increment the corresponding index in the alpha array
				alpha[ch-'a']++ // 'a' is at index 0, 'b' at index 1, ..., 'z' at index 25
			}
		}
	}

	// Print the count of each letter from 'a' to 'z'
	for i := 0; i < 26; i++ {
		ch := 'a' + rune(i) // Start with the letter 'a'
		fmt.Printf("%c : %d\n", ch, alpha[i]) // Output the letter and its count
	}
}

// <END-OF-CODE>

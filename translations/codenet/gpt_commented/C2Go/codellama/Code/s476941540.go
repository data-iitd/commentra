package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func main() {
	// Declare variables: 'i' for loop control, 'alpha' array to count occurrences of each letter, and 'ch' for character input
	var i int
	alpha := make([]int, 26)
	var ch rune

	// Initialize the alpha array to zero for all 26 letters of the alphabet
	for i = 0; i < 26; i++ {
		alpha[i] = 0
	}

	// Infinite loop to read characters until EOF (End of File) is encountered
	for {
		ch = nextChar()
		if ch == 0 {
			break
		}

		// Check if the character is an alphabet letter
		if unicode.IsLetter(ch) {
			// If the character is uppercase, increment the corresponding index in the alpha array
			if unicode.IsUpper(ch) {
				alpha[ch-65]++ // 'A' is at index 0, 'B' at index 1, ..., 'Z' at index 25
			} else {
				// If the character is lowercase, increment the corresponding index in the alpha array
				alpha[ch-97]++ // 'a' is at index 0, 'b' at index 1, ..., 'z' at index 25
			}
		}
	}

	// Print the count of each letter from 'a' to 'z'
	ch = 'a' // Start with the letter 'a'
	for i = 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", ch, alpha[i]) // Output the letter and its count
		ch++
	}
}

func nextChar() rune {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanRunes)
	scanner.Scan()
	return rune(scanner.Text()[0])
}


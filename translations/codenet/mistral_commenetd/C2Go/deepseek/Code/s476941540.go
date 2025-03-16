package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func main() {
	var i int
	var alpha [26]int
	var ch rune

	// Initialize all elements of the array 'alpha' to zero
	for i = 0; i < 26; i++ {
		alpha[i] = 0
	}

	// Create a new scanner to read from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Start an infinite loop to read characters from the input
	for scanner.Scan() {
		ch = rune(scanner.Text()[0]) // Read a character from the standard input

		// If the character read is End-Of-File (EOF), break the loop
		if ch == -1 {
			break
		}

		// If the character is an alphabetic character
		if unicode.IsLetter(ch) {
			// If the character is an uppercase letter, increment the corresponding element in the array 'alpha'
			if unicode.IsUpper(ch) {
				alpha[ch-'A']++
			}

			// If the character is a lowercase letter, increment the corresponding element in the array 'alpha'
			if unicode.IsLower(ch) {
				alpha[ch-'a']++
			}
		}
	}

	// Initialize the character 'ch' with the ASCII value of 'a'
	ch = 'a'

	// Print the count of each alphabetic character and its corresponding ASCII value
	for i = 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", ch, alpha[i])
		ch++
	}
}


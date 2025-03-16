package main

import (
	"fmt"
	"os"
	"bufio"
	"unicode"
)

func main() {
	var alpha [26]int // Declare an array 'alpha' of size 26

	// Create a buffered reader to read from standard input
	reader := bufio.NewReader(os.Stdin)

	// Start an infinite loop
	for {
		ch, _, err := reader.ReadRune() // Read a character from the standard input
		if err != nil { // If there's an error (like EOF), break the loop
			break
		}

		// If the character is an alphabetic character
		if unicode.IsLetter(ch) {
			// If the character is an uppercase letter, increment the corresponding element in the array 'alpha'
			if unicode.IsUpper(ch) {
				alpha[ch-'A']++
			} else { // If the character is a lowercase letter, increment the corresponding element in the array 'alpha'
				alpha[ch-'a']++
			}
		}
	}

	// Print the count of each alphabetic character
	for i := 0; i < 26; i++ {
		ch := 'a' + rune(i) // Calculate the character corresponding to the index
		fmt.Printf("%c : %d\n", ch, alpha[i])
	}
}

// <END-OF-CODE>

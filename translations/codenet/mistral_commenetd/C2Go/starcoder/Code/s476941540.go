<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func main() {
	var (
		ch   rune
		i    int
		alpha [26]int
	)

	// Initialize all elements of the array 'alpha' to zero
	for i = 0; i < 26; i++ {
		alpha[i] = 0
	}

	// Start an infinite loop
	for {
		ch, _, _ = bufio.NewReader(os.Stdin).ReadRune()

		// If the character read is End-Of-File (EOF), break the loop
		if ch == rune(os.EOF) {
			break
		}

		// If the character is an alphabetic character
		if unicode.IsLetter(ch) {
			// If the character is an uppercase letter, increment the corresponding element in the array 'alpha'
			if unicode.IsUpper(ch) {
				alpha[ch - 'A']++
			}

			// If the character is a lowercase letter, increment the corresponding element in the array 'alpha'
			else {
				alpha[ch - 'a']++
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


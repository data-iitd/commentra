<<<<<<< HEAD

import (
    "bufio"
    "fmt"
    "os"
    "unicode"
)

func main() {
    var (
        ch rune
        i  int
        alpha [26]int
    )

    // Initialize the alpha array to zero for all elements
    for i = 0; i < 26; i++ {
        alpha[i] = 0
    }

    // Read characters from the standard input until EOF
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        ch = scanner.Text()[0]

        // Check if the character is an alphabetic character
        if unicode.IsLetter(ch) {
            // Increment the corresponding element in alpha based on case
            if unicode.IsUpper(ch) {
                alpha[ch - 65]++
            } else {
                alpha[ch - 97]++
            }
        }
    }

    // Print the counts of each letter from 'a' to 'z'
    ch = 'a'
    for i = 0; i < 26; i++ {
        fmt.Printf("%c : %d\n", ch, alpha[i])
        ch++
    }
=======
package main

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

	// Initialize the alpha array to zero for all elements
	for i = 0; i < 26; i++ {
		alpha[i] = 0
	}

	// Read characters from the standard input until EOF
	reader := bufio.NewReader(os.Stdin)
	for {
		ch, _, err := reader.ReadRune()
		if err!= nil {
			break
		}

		// Check if the character is an alphabetic character
		if unicode.IsLetter(ch) {
			// Increment the corresponding element in alpha based on case
			if unicode.IsUpper(ch) {
				alpha[ch - 65]++
			} else {
				alpha[ch - 97]++
			}
		}
	}

	// Print the counts of each letter from 'a' to 'z'
	ch = 'a'
	for i = 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", ch, alpha[i])
		ch++
	}
>>>>>>> 98c87cb78a (data updated)
}


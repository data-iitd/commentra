package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize a Scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the next line from the console
	scanner.Scan()
	s := scanner.Text()

	// Get the length of the string 's'
	length := len(s)

	// Initialize a variable 'ch' to store the first non-space and non-question mark character found in the string 's'
	var ch rune

	// Iterate through the string 's' from the end to the beginning
	for i := length - 1; i >= 0; i-- {
		// Check if the current character is not a space or a question mark
		if s[i] != ' ' && s[i] != '?' {
			// If yes, store the character in 'ch' and break out of the loop
			ch = rune(s[i])
			break
		}
	}

	// Convert the character 'ch' to lowercase
	ch = rune(strings.ToLower(string(ch))[0])

	// Check if the character 'ch' is a vowel or a y
	if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' {
		// If yes, print "YES" to the console
		fmt.Println("YES")
	} else {
		// If no, print "NO" to the console
		fmt.Println("NO")
	}
}

// <END-OF-CODE>

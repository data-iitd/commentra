package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Function to check if a character is a lowercase Latin letter
func isLatinLetter(c byte) bool {
	return c >= 'a' && c <= 'z'
}

// Function to check if a character is a punctuation mark
func isPunctuation(c byte) bool {
	switch c {
	case '.':
		return true
	case ',':
		return true
	case '!':
		return true
	case '?':
		return true
	default:
		return false
	}
}

func main() {
	// Create a new Scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	// Read a line of input from the user
	scanner.Scan()
	s := scanner.Text()
	// Initialize a StringBuilder to construct the output string
	var sb strings.Builder
	n := len(s) // Get the length of the input string
	
	// Append the first character of the input string to the StringBuilder
	sb.WriteByte(s[0])
	
	// Loop through the input string starting from the second character
	for i := 1; i < n; i++ {
		c := s[i] // Get the current character
		
		// Check if the current character is a Latin letter
		if isLatinLetter(c) {
			// If the previous character is not a Latin letter, append a space
			if !isLatinLetter(s[i-1]) {
				sb.WriteByte(' ')
			}
			// Append the current Latin letter to the StringBuilder
			sb.WriteByte(c)
		} 
		// Check if the current character is a punctuation mark
		else if isPunctuation(c) {
			sb.WriteByte(c) // Append the punctuation mark to the StringBuilder
		}
	}
	
	// Print the constructed output string
	fmt.Println(sb.String())
}


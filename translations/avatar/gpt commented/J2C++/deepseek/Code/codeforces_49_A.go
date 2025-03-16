package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

func main() {
	// Create a new Scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read a line of input from the user
	scanner.Scan()
	input := scanner.Text()
	
	// Get the length of the input string
	length := len(input)
	
	// Initialize a character variable to store the last non-space, non-question mark character
	var ch rune
	
	// Loop through the string in reverse to find the last relevant character
	for i := length - 1; i >= 0; i-- {
		// Check if the current character is not a space or a question mark
		if input[i] != ' ' && input[i] != '?' {
			ch = rune(input[i]) // Store the character
			break // Exit the loop once the character is found
		}
	}
	
	// Convert the character to lowercase for uniform comparison
	ch = unicode.ToLower(ch)
	
	// Check if the character is a vowel or 'y'
	if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' {
		fmt.Println("YES") // Print "YES" if it is a vowel
	} else {
		fmt.Println("NO") // Print "NO" if it is not a vowel
	}
}

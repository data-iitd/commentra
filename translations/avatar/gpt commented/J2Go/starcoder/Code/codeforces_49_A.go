package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input from stdin
	input, _ := reader.ReadString('\n')

	// Remove the newline character
	input = strings.Replace(input, "\n", "", -1)

	// Convert the input to lowercase
	input = strings.ToLower(input)

	// Initialize a variable to store the last non-space, non-question mark character
	lastChar := 0

	// Loop through the string in reverse to find the last relevant character
	for i := len(input) - 1; i >= 0; i-- {
		// Check if the current character is not a space or a question mark
		if input[i]!='' && input[i]!= '?' {
			lastChar = input[i] // Store the character
			break               // Exit the loop once the character is found
		}
	}

	// Convert the character to lowercase for uniform comparison
	lastChar = rune(lastChar)

	// Check if the character is a vowel or 'y'
	if lastChar == 'a' || lastChar == 'e' || lastChar == 'i' || lastChar == 'o' || lastChar == 'u' || lastChar == 'y' {
		fmt.Println("YES") // Print "YES" if it is a vowel
	} else {
		fmt.Println("NO") // Print "NO" if it is not a vowel
	}
}


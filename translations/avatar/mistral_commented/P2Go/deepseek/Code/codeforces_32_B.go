package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')

	// Remove the newline character at the end of the input string
	s = s[:len(s)-1]

	// Initialize an empty string to store the result
	var result string

	// Initialize a variable 'i' to traverse the string 's'
	i := 0

	// Use a while loop to traverse the string 's' until the end
	for i < len(s) {
		// Check if the current character is a '.'
		if s[i] == '.' {
			// If yes, append '0' to the result string
			result += "0"
		} else {
			// Move to the next character
			i++
			// Check if the next character is also a '.'
			if i < len(s) && s[i] == '.' {
				// If yes, append '1' to the result string
				result += "1"
			} else {
				// If not, append '2' to the result string
				result += "2"
			}
		}
		// Move to the next character
		i++
	}

	// Print the final result string
	fmt.Println(result)
}


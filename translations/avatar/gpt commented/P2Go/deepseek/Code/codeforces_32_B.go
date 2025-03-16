package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read input string from the user
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')

	// Initialize an empty string to store the result
	var result string

	// Initialize a counter variable to iterate through the input string
	i := 0

	// Loop through each character in the input string
	for i < len(s) {
		// Check if the current character is a dot
		if s[i] == '.' {
			// If it is a dot, append '0' to the result
			result += "0"
		} else {
			// If it is not a dot, increment the index to check the next character
			i++

			// Check the next character
			if i < len(s) && s[i] == '.' {
				// If the next character is a dot, append '1' to the result
				result += "1"
			} else {
				// If the next character is not a dot, append '2' to the result
				result += "2"
			}
		}

		// Increment the index to move to the next character in the input string
		i++
	}

	// Print the final result string
	fmt.Println(result)
}


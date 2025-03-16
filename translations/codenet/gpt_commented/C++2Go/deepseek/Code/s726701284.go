package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare a string variable to store the input
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')

	// Loop through each character from 'a' to 'z'
	for i := 'a'; i <= 'z'; i++ {
		// Initialize a counter to track occurrences of the current character
		var a int

		// Loop through each character in the input string
		for j := 0; j < len(s); j++ {
			// Check if the current character matches the character being checked
			if i == rune(s[j]) {
				// Increment the counter if a match is found
				a++
			}
		}

		// If the character was not found in the input string
		if a == 0 {
			// Output the first missing character and exit the loop
			fmt.Println(string(i))
			break
		}

		// If we reach the end of the alphabet and all characters are present
		if i == 'z' {
			// Output "None" if no characters are missing
			fmt.Println("None")
			break
		}
	}
}


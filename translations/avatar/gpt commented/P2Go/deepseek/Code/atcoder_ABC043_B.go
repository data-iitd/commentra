package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read input from the user
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	// Initialize an empty string to store the resulting characters
	var myStr string

	// Iterate through each character in the input string
	for _, c := range input {
		// Check if the character is '0' or '1'
		if c == '0' || c == '1' {
			// If it is, append it to the result string
			myStr += string(c)
		} else if c == 'B' && len(myStr) != 0 {
			// If it is, remove the last character from the result string
			myStr = myStr[:len(myStr)-1]
		}
	}

	// Print the final result string
	fmt.Println(myStr)
}


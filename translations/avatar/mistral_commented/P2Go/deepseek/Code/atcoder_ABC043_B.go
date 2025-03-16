package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new reader to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Read the user input string
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')

	// Remove the newline character from the input string
	s = s[:len(s)-1]

	// Initialize an empty string variable to store the binary string
	var myStr string

	// Iterate through each character in the user input string
	for _, c := range s {
		// If the character is '0' or '1', append it to the binary string
		if c == '0' || c == '1' {
			myStr += string(c)
		} else if c == 'B' && len(myStr) != 0 {
			// If the character is 'B', remove the last character from the binary string before 'B' was encountered
			myStr = myStr[:len(myStr)-1]
		}
	}

	// Print the final binary string
	fmt.Println(myStr)
}

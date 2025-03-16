package main

import (
	"fmt"
)

func main() {
	// Ask the user for a string input
	var s string
	fmt.Scanln(&s)

	// Initialize an empty string variable to store the binary string
	myStr := ""

	// Iterate through each character in the user input string
	for _, c := range s {
		// If the character is '0' or '1', append it to the binary string
		if c == '0' || c == '1' {
			myStr += string(c)
		// If the character is 'B', remove the last character from the binary string before 'B' was encountered
		} else if c == 'B' && len(myStr) != 0 {
			myStr = myStr[:len(myStr)-1]
		}
	}

	// Print the final binary string
	fmt.Println(myStr)
}

// <END-OF-CODE>

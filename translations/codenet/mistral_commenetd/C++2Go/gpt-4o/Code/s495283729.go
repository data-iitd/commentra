package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string // Declare a string variable 's' to store the input string

	fmt.Scan(&s) // Read a string from the standard input and store it in 's'

	flag := 0 // Initialize a boolean flag

	for i := 0; i < len(s); i++ { // Iterate through each character in the string 's'
		if i%2 == 0 { // Check if the current index 'i' is even
			switch s[i] { // Switch statement to check the character at the even index
			case 'R', 'U', 'D': // If the character is 'R', 'U', or 'D', do nothing
			default: // If the character is not 'R', 'U', or 'D', set the flag to 1
				flag = 1
			}
		} else { // If the current index 'i' is odd
			switch s[i] { // Switch statement to check the character at the odd index
			case 'L', 'U', 'D': // If the character is 'L', 'U', or 'D', do nothing
			default: // If the character is not 'L', 'U', or 'D', set the flag to 1
				flag = 1
			}
		}
	}

	if flag == 0 { // If no invalid character was found during the iteration
		fmt.Println("Yes") // Output "Yes" to the standard output
	} else { // If an invalid character was found during the iteration
		fmt.Println("No") // Output "No" to the standard output
	}
}

// <END-OF-CODE>

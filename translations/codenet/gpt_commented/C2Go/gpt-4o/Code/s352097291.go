package main

import (
	"fmt"
)

func main() {
	// Declare a character array 'c' to store the input string and 'ans' to store the result
	var c string
	ans := ""

	// Read a string input from the user
	fmt.Scan(&c)

	// Iterate through each character of the input string
	for _, char := range c {
		// If the current character is not 'B', append it to the 'ans' string
		if char != 'B' {
			ans += string(char)
		} else {
			// If the current character is 'B', remove the last character from 'ans' (if it exists)
			if len(ans) > 0 {
				ans = ans[:len(ans)-1]
			}
		}
	}

	// Print the resulting string after processing the input
	fmt.Println(ans)
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a string 'c' to store the input string and 'ans' to store the result
	var c, ans string

	// Read a string input from the user
	fmt.Scan(&c)

	// Iterate through each character of the input string until the null terminator is encountered
	for i := 0; i < len(c); i++ {
		// If the current character is not 'B', append it to the 'ans' string
		if c[i] != 'B' {
			ans += string(c[i])
		} else {
			// If the current character is 'B', remove the last character from 'ans' (if it exists)
			ans = strings.TrimSuffix(ans, string(c[i]))
		}
	}

	// Print the resulting string after processing the input
	fmt.Println(ans)
}


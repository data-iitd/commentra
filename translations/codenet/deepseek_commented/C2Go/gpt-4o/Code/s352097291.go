package main

import (
	"fmt"
)

func main() {
	var c string
	var ans []rune // Use a slice of runes to handle characters

	fmt.Scan(&c) // Read input string into c

	// Process the input string
	for _, char := range c {
		if char != 'B' {
			ans = append(ans, char) // Append character to ans if not 'B'
		} else if len(ans) > 0 {
			ans = ans[:len(ans)-1] // Remove last character from ans if 'B'
		}
	}

	fmt.Println(string(ans)) // Output the result string ans
}

// <END-OF-CODE>

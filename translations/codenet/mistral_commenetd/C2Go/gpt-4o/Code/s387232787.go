package main

import (
	"fmt"
	"os"
)

func main() {
	// Initialize a slice 'c' of size 26 to store the count of each character.
	c := make([]int, 26)

	var str string // Declare a string 'str' to store the input string.

	// Use a loop to read strings from the standard input until the end of file is reached.
	for {
		_, err := fmt.Scan(&str)
		if err != nil {
			break // Break the loop if there is an error (EOF).
		}

		// Use a loop to traverse the string 'str'.
		for _, p := range str {
			// Use nested if conditions to check if the current character is a lowercase or uppercase letter.
			if 'a' <= p && p <= 'z' {
				// Increment the count of the corresponding character in the 'c' slice.
				c[p-'a']++
			} else if 'A' <= p && p <= 'Z' {
				// Increment the count of the corresponding character in the 'c' slice.
				c[p-'A']++
			}
		}
	}

	// Use a loop to print the count of each character and its corresponding character.
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

// <END-OF-CODE>

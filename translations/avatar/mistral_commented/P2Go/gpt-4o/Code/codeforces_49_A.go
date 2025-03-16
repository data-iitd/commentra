package main

import (
	"fmt"
	"strings"
)

func main() {
	// Define a slice containing all the vowels in upper and lower case
	vo := []string{"a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y"}

	// Take an input string 'a' from the user
	var a string
	fmt.Scanln(&a)

	// Iterate through the string 'a' from the end to the beginning
	for i := len(a) - 1; i >= 0; i-- {
		// If the current character is a space or a question mark, skip it and move on to the next character
		if a[i] == ' ' || a[i] == '?' {
			continue
		} else {
			// If the current character is not a space or a question mark, check if it is a vowel or not
			currentChar := string(a[i])
			// Check if the current character is a vowel
			if contains(vo, currentChar) {
				// If it is, print "YES" and break out of the loop
				fmt.Println("YES")
				break
			} else {
				// If it is not, print "NO" and break out of the loop
				fmt.Println("NO")
				break
			}
		}
	}
}

// Function to check if a slice contains a specific string
func contains(slice []string, item string) bool {
	for _, v := range slice {
		if v == item {
			return true
		}
	}
	return false
}

// <END-OF-CODE>

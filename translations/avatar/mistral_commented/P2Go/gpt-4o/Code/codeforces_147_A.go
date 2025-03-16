package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take user input as a string 's'
	var s string
	fmt.Scanln(&s)

	// Initialize an empty slice 'res' to store the final result
	var res []string

	// Define a slice 'punctuation' containing all the punctuation marks
	punctuation := []string{",", ".", "!", "?"}

	// Iterate through each character in the string 's'
	for i := 0; i < len(s); i++ {
		currentChar := string(s[i])

		// If current character is a space and previous character is not empty,
		// append the space to the result slice
		if i >= 1 {
			if currentChar == " " {
				if len(res) > 0 && res[len(res)-1] != " " {
					// Append space to the result slice
					res = append(res, currentChar)
				}
			} else if contains(punctuation, currentChar) {
				// If current character is a punctuation mark
				if len(res) > 0 && res[len(res)-1] == " " {
					res = res[:len(res)-1] // pop the last character
					res = append(res, currentChar, " ")
				} else {
					res = append(res, currentChar)
				}
			} else {
				// If current character is not a space and is not a punctuation mark,
				// simply append it to the result slice
				res = append(res, currentChar)
			}
		} else {
			// For the first character
			res = append(res, currentChar)
		}
	}

	// Join all the elements of the result slice and print the final string
	fmt.Print(strings.Join(res, ""))
}

// Helper function to check if a string is in a slice
func contains(slice []string, item string) bool {
	for _, v := range slice {
		if v == item {
			return true
		}
	}
	return false
}

// <END-OF-CODE>

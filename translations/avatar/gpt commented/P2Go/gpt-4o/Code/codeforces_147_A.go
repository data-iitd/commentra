package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take input from the user
	var s string
	fmt.Scanln(&s)

	// Initialize an empty slice to store the result
	var res []string

	// Define a slice of punctuation marks to check against
	punctuation := []string{",", ".", "!", "?"}

	// Iterate through each character in the input string
	for i, char := range s {
		// Check if the current index is greater than or equal to 1
		if i >= 1 {
			// If the current character is a space
			if char == ' ' {
				// Only append a space if the last element in res is not a space
				if len(res) == 0 || res[len(res)-1] != " " {
					res = append(res, " ")
				}
			} else {
				// If the current character is a punctuation mark
				if contains(punctuation, string(char)) {
					// If the last element in res is a space, remove it
					if len(res) > 0 && res[len(res)-1] == " " {
						res = res[:len(res)-1]
					}
					// Append the punctuation mark to the result
					res = append(res, string(char))
					// Append a space after the punctuation
					res = append(res, " ")
				} else {
					// If the current character is not punctuation, append it to the result
					res = append(res, string(char))
				}
			}
		} else {
			// For the first character, handle it separately
			if char != ' ' && !contains(punctuation, string(char)) {
				// Append the first character to the result if it's not a space or punctuation
				res = append(res, string(char))
			}
		}
	}

	// Join the slice into a single string and print the result
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

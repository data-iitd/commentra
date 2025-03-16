package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanln(&s) // Take input string from user
	res := []rune{} // Initialize an empty slice to store the result
	punctuation := []rune{',', '.', '!', '?'} // Define a slice of punctuation marks

	// Iterate over each character in the input string
	for i, char := range s {
		if i >= 1 { // Check if it's not the first character
			if char == ' ' { // Check if the current character is a space
				if len(res) > 0 && res[len(res)-1] != ' ' { // Check if the last character in res is not a space
					res = append(res, char) // Append the current space to res
				}
			} else { // If the current character is not a space
				if contains(punctuation, char) { // Check if the current character is a punctuation mark
					if len(res) > 0 && res[len(res)-1] == ' ' { // Check if the last character in res is a space
						res = res[:len(res)-1] // Remove the last character (space) from res
					}
					res = append(res, char) // Append the punctuation mark to res
					res = append(res, ' ') // Append a space after the punctuation mark
				} else {
					res = append(res, char) // Append the character to res if it's not a punctuation mark
				}
			}
		} else { // For the first character
			if char == ' ' { // Check if the first character is a space
				continue // Skip the first space
			}
			if contains(punctuation, char) { // Check if the first character is a punctuation mark
				continue // Skip the first punctuation mark
			} else {
				res = append(res, char) // Append the first character to res
			}
		}
	}

	// Join the slice res into a string and print it
	fmt.Println(string(res))
}

// Function to check if a rune is in a slice of runes
func contains(slice []rune, item rune) bool {
	for _, v := range slice {
		if v == item {
			return true
		}
	}
	return false
}

// <END-OF-CODE>

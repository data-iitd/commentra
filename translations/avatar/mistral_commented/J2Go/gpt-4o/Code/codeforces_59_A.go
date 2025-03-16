package main

import (
	"fmt"
	"strings"
)

func main() {
	var word string
	fmt.Scan(&word) // Reading the first word as input from the user

	uppercase := 0 // Initializing a counter for uppercase characters
	lowercase := 0 // Initializing a counter for lowercase characters

	for _, ch := range word { // Iterating through each character in the word
		if ch >= 'A' && ch <= 'Z' { // Checking if the character is uppercase
			uppercase++ // Incrementing the uppercase counter
		} else if ch >= 'a' && ch <= 'z' { // Checking if the character is lowercase
			lowercase++ // Incrementing the lowercase counter
		}
	}

	if uppercase > lowercase { // Checking if there are more uppercase characters than lowercase characters
		fmt.Println(strings.ToUpper(word)) // Printing the word in uppercase if condition is true
	} else if lowercase > uppercase { // Checking if there are more lowercase characters than uppercase characters
		fmt.Println(strings.ToLower(word)) // Printing the word in lowercase if condition is true
	} else { // If both uppercase and lowercase characters are equal
		fmt.Println(strings.ToLower(word)) // Printing the word in lowercase if both conditions are false
	}
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"strings"
)

func main() {
	var word string
	fmt.Scan(&word) // Reading a single word from the user input

	uppercase := 0 // Initializing the counter for uppercase letters
	lowercase := 0 // Initializing the counter for lowercase letters

	// Looping through each character in the input word
	for _, ch := range word {
		if ch >= 'A' && ch <= 'Z' { // Checking if the character is uppercase
			uppercase++ // Incrementing the uppercase counter
		} else if ch >= 'a' && ch <= 'z' { // Checking if the character is lowercase
			lowercase++ // Incrementing the lowercase counter
		}
	}

	// Comparing the counts of uppercase and lowercase letters and printing the result accordingly
	if uppercase > lowercase {
		fmt.Println(strings.ToUpper(word)) // Printing the word in uppercase if there are more uppercase letters
	} else if lowercase > uppercase {
		fmt.Println(strings.ToLower(word)) // Printing the word in lowercase if there are more lowercase letters
	} else {
		fmt.Println(strings.ToLower(word)) // Printing the word in lowercase if the counts are equal
	}
}

// <END-OF-CODE>

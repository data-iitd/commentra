package main

import (
	"fmt"
	"strings"
)

func main() {
	var word string
	fmt.Scan(&word) // Reading a single word from the user input

	uppercase := 0
	lowercase := 0

	// Looping through each character in the input word
	for _, ch := range word {
		if strings.ToUpper(string(ch)) == string(ch) { // Checking if the character is uppercase
			uppercase++ // Incrementing the uppercase counter
		} else {
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

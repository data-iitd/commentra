package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Creating a new scanner to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Prompting the user to enter a word
	fmt.Print("Enter a word: ")
	word, _ := reader.ReadString('\n')

	// Initializing counters for uppercase and lowercase letters
	uppercase := 0
	lowercase := 0

	// Looping through each character in the input word
	for _, ch := range word {
		// Checking if the character is uppercase
		if strings.ToUpper(string(ch)) == string(ch) {
			uppercase++ // Incrementing the uppercase counter
		} else {
			lowercase++ // Incrementing the lowercase counter
		}
	}

	// Comparing the counts of uppercase and lowercase letters
	if uppercase > lowercase {
		// If there are more uppercase letters, print the word in uppercase
		fmt.Println(strings.ToUpper(word))
	} else if lowercase > uppercase {
		// If there are more lowercase letters, print the word in lowercase
		fmt.Println(strings.ToLower(word))
	} else {
		// If the counts are equal, print the word in lowercase
		fmt.Println(strings.ToLower(word))
	}
}


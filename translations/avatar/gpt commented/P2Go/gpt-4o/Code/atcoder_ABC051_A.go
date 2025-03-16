package main

import (
	"fmt"
	"strings"
)

func main() {
	// Prompt the user for input
	var userInput string
	fmt.Scanln(&userInput)

	// Replace all commas in the input string with spaces
	modifiedInput := strings.ReplaceAll(userInput, ",", " ")

	// Print the modified input string
	fmt.Println(modifiedInput)
}

// <END-OF-CODE>

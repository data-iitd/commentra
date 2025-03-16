package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new reader for reading input from the user
	reader := bufio.NewReader(os.Stdin)

	// Prompt the user for input and read the input string
	fmt.Print("Enter input: ")
	userInput, _ := reader.ReadString('\n')

	// Remove the newline character from the input string
	userInput = strings.TrimSuffix(userInput, "\n")

	// Replace all commas in the input string with spaces
	modifiedInput := strings.ReplaceAll(userInput, ",", " ")

	// Print the modified input string
	fmt.Println(modifiedInput)
}


package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read a line from input
	var inputString string
	fmt.Scanln(&inputString)

	// Replace all commas with spaces in the input string
	modifiedString := strings.ReplaceAll(inputString, ",", " ")

	// Print the modified string to the console
	fmt.Println(modifiedString)
}

// <END-OF-CODE>

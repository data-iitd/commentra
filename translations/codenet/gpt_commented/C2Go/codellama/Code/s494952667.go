package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a string to hold the input string
	var str string

	// Read a string from standard input
	fmt.Scan(&str)

	// Calculate the length of the input string
	len := len(str)

	// Loop through the string in reverse order
	for i := len - 1; i >= 0; i-- {
		// Output each character of the string in reverse
		fmt.Print(string(str[i]))
	}

	// Print a newline character after the reversed string
	fmt.Println()
}


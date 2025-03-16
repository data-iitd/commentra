package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare a character array to hold the input string (maximum length 20 + 1 for null terminator)
	var str [21]byte
	var i, len int

	// Read a string from standard input
	fmt.Scanf("%s", &str)

	// Calculate the length of the input string
	len = len(str)

	// Loop through the string in reverse order
	for i = len - 1; i >= 0; i-- {
		// Output each character of the string in reverse
		fmt.Printf("%c", str[i])
	}

	// Print a newline character after the reversed string
	fmt.Printf("\n")
}


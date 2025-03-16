package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a string variable to hold the input string (maximum length 20 + 1 for null terminator)
	var str string
	var i, len int
	
	// Read a string from standard input
	fmt.Scanln(&str)
	
	// Calculate the length of the input string
	len = len(str)

	// Loop through the string in reverse order
	for i = len - 1; i >= 0; i-- {
		// Output each character of the string in reverse
		fmt.Printf("%c", str[i])
	}
	
	// Print a newline character after the reversed string
	fmt.Println()
}


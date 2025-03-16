package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a string variable to hold the input string with a maximum length of 100 characters
	var mes string

	// Read a string from standard input and store it in the 'mes' variable
	fmt.Scanln(&mes)

	// Print the first character of the string, the length of the string minus 2, and the last character of the string
	fmt.Printf("%c%lu%c\n", mes[0], uint64(len(mes))-2, mes[len(mes)-1])
}


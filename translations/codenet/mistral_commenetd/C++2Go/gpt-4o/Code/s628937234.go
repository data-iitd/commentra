package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s string // Declare a string variable s

	fmt.Scan(&s) // Read a string from the standard input and store it in the variable s

	// Create a new string t from the string s
	t := string(s[0]) // Extract the first character from string s
	t += strconv.Itoa(len(s) - 2) // Convert the size of string s minus 2 to a string
	t += string(s[len(s)-1]) // Concatenate the last character of string s

	fmt.Println(t) // Output the newly created string t to the standard output
}

// <END-OF-CODE>

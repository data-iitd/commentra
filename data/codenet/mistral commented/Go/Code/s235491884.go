// Package main is the entry point of the program
package main

import (
	// Importing the 'fmt' package for formatted I/O functions
	"fmt"
	// Importing the 'strings' package for string manipulation functions
	"strings"
)

// Function main is the entry point of the program
func main() {
	// Declare a variable 's' of type string
	var s string
	// Use 'fmt.Scan' to read a string input from the standard input
	fmt.Scan(&s)

	// Use 'strings.Count' to count the number of occurrences of the substring "o" in the string 's'
	n := strings.Count(s, "o")

	// Calculate the result by adding 700 to the product of 100 and the number of occurrences of "o" in the string
	result := 700 + n*100
	// Use 'fmt.Println' to print the result to the standard output
	fmt.Println(result)
}

// The code ends here

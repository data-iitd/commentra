package main

import (
	"fmt"      // Importing the fmt package for formatted I/O
	"strings"  // Importing the strings package for string manipulation functions
)

func main() {
	var s string // Declare a variable 's' to hold the input string
	fmt.Scan(&s) // Read a string from standard input and store it in 's'

	// Count the occurrences of the letter 'o' in the input string 's'
	n := strings.Count(s, "o")

	// Calculate the result based on the count of 'o' and print it
	// The formula adds 700 to 100 times the count of 'o'
	fmt.Println(700 + n*100)
}

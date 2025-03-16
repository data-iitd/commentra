package main

import (
	"fmt"      // Importing the fmt package for formatted I/O operations
	"strings"  // Importing the strings package for string manipulation functions
)

// Main function where the execution of the program begins
func main() {
	var s string // Declare a variable 's' to hold the input string

	// Read a string input from the user and store it in variable 's'
	fmt.Scanf("%s", &s)

	// Replace all occurrences of "2017" with "2018" in the input string and print the result
	fmt.Println(strings.Replace(s, "2017", "2018", -1))
}

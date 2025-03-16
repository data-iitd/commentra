// Package main is the entry point of the program
package main

import (
	// Import the "fmt" and "strings" packages
	"fmt"
	"strings"
)

func main() {
	// Declare two variables, n and s
	var n int
	var s string

	// Read the input from the standard input
	fmt.Scan(&n, &s)

	// Print the result of the strings.Count function
	fmt.Println(strings.Count(s, "ABC"))
}

// The main function is the entry point of the program
func main() {
	// Declare two variables, n and s
	var n int
	var s string

	// Read the input from the standard input
	fmt.Scan(&n, &s)

	// Call the strings.Count function to count the number of occurrences of "ABC" in the string s
	// Print the result using the fmt.Println function
	fmt.Println(strings.Count(s, "ABC"))
}

// This is the end of the code

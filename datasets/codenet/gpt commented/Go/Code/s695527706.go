package main

import (
	"fmt"      // Importing the fmt package for formatted I/O
	"strings"  // Importing the strings package for string manipulation functions
)

func main() {
	var n int    // Declare a variable n to hold the length of the string
	var s string // Declare a variable s to hold the input string

	// Read input values for n and s from the standard input
	fmt.Scan(&n, &s)

	// Count and print the number of occurrences of the substring "ABC" in the string s
	fmt.Println(strings.Count(s, "ABC"))
}

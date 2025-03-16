package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare variables for input strings
	var str, p string

	// Read two strings from standard input
	fmt.Scan(&str, &p)

	// Concatenate the original string with itself
	tmp := str
	str += tmp

	// Check if the pattern p is found in the concatenated string str
	if strings.Contains(str, p) {
		fmt.Println("Yes") // Output "Yes" if the pattern is found
	} else {
		fmt.Println("No") // Output "No" if the pattern is not found
	}
}

// <END-OF-CODE>

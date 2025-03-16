// Package declaration, this file is the entry point of the program
package main

// Import statements, importing the fmt and strings packages
import (
	"fmt"
	"strings"
)

// Entry point of the program
func main() {
	// Initialize a variable s of type string and read a string input from the standard input
	var s string
	fmt.Scanf("%s", &s)

	// Initialize a variable ans with the string value "No"
	ans := "No"

	// Check if the index of the substring "C" in the string s is less than the index of the substring "F"
	if strings.Index(s, "C") < strings.LastIndex(s, "F") {
		// If it is, then change the value of ans to "Yes"
		ans = "Yes"
	}

	// Check if the index of the substring "C" in the string s is less than 0
	if strings.Index(s, "C") < 0 {
		// If it is, then do not change the value of ans
	}

	// Print the value of ans to the standard output
	fmt.Printf("%s\n", ans)
}

// End of the code

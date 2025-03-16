package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a variable to hold the input string
	var s string
	
	// Read a string input from the user
	fmt.Scanf("%s", &s)
	
	// Initialize the answer variable with "No"
	ans := "No"
	
	// Check if the first occurrence of 'C' is before the last occurrence of 'F'
	if strings.Index(s, "C") < strings.LastIndex(s, "F") {
		// If true, set the answer to "Yes"
		ans = "Yes"
	}
	
	// Check if 'C' does not exist in the string
	if strings.Index(s, "C") < 0 {
		// If true, set the answer to "No"
		ans = "No"
	}
	
	// Print the final answer
	fmt.Printf("%s\n", ans)
}

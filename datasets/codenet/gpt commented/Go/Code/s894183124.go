package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare variables to hold the integer input and the string input
	var n int
	var s string
	
	// Read an integer from standard input
	fmt.Scanf("%d", &n)
	
	// Read a string from standard input
	fmt.Scanf("%s", &s)
	
	// Count the occurrences of the substring "ABC" in the input string
	// and print the result
	fmt.Printf("%d\n", strings.Count(s, "ABC"))
}

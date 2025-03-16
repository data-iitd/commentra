// Package main is the entry point of our Go program
package main

import (
	// We import the "fmt" package to enable input/output operations
	"fmt"
	// We import the "strings" package to use the "Count" function
	"strings"
)

func main() {
	// Declare and initialize two variables: n of type int and s of type string
	var n int
	var s string

	// Use the fmt package to read input from the standard input
	fmt.Scanf("%d", &n)
	fmt.Scanf("%s", &s)

	// Use the fmt and strings packages to compute and print the result
	fmt.Printf("%d\n", strings.Count(s, "ABC"))
}

// End of code

package main

import (
	"fmt"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	var in = new(Scanner)

	// Read an integer K from the user, which represents the maximum length of the string to display
	var K int
	fmt.Scan(&K)

	// Read a string S from the user
	var S string
	fmt.Scan(&S)

	// Check if the length of the string S is less than or equal to K
	if len(S) <= K {
		// If true, print the string S as it is
		fmt.Println(S)
	} else {
		// If false, print the first K characters of S followed by "..."
		fmt.Println(S[:K] + "...")
	}

	// Close the scanner to prevent resource leaks
	in.Close()
}


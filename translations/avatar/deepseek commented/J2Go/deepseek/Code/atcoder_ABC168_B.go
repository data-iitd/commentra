package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the user
	var K int
	var S string

	// Read an integer K from the user
	fmt.Scan(&K)

	// Read a string S from the user
	fmt.Scan(&S)

	// Check if the length of the string S is less than or equal to K
	if len(S) <= K {
		// If true, print the string S as it is
		fmt.Println(S)
	} else {
		// If false, truncate the string to the first K characters and append "..."
		fmt.Println(S[:K] + "...")
	}
}


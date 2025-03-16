package main

import (
	"fmt"
)

func main() {
	// Create a variable to hold the maximum length of the string to display
	var K int
	// Read an integer K from the user
	fmt.Scan(&K)

	// Create a variable to hold the string S
	var S string
	// Read a string S from the user
	fmt.Scan(&S)

	// Check if the length of the string S is less than or equal to K
	if len(S) <= K {
		// If true, print the string S as it is
		fmt.Println(S)
	} else {
		// If false, print the first K characters of S followed by "..."
		fmt.Println(S[:K] + "...")
	}
}

// <END-OF-CODE>

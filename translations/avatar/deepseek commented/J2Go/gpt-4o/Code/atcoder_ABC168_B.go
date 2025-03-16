package main

import (
	"fmt"
)

func main() {
	// Create a variable to read an integer K from the user
	var K int
	fmt.Scan(&K)

	// Create a variable to read a string S from the user
	var S string
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

// <END-OF-CODE>

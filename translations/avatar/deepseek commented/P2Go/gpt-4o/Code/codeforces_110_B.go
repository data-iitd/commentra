package main

import (
	"fmt"
)

func main() {
	LUCKY := "abcd"
	// Define a string LUCKY containing the characters "abcd"

	var n int
	fmt.Scan(&n)
	// Take an integer input n from the user

	s := ""
	// Initialize an empty string s to store the result

	for i := 0; i < n; i++ {
		// Loop n times to construct the string s
		s += string(LUCKY[i%4])
		// Append a character from LUCKY to s based on the index i modulo 4
	}

	fmt.Println(s)
	// Print the final string s
}

// <END-OF-CODE>

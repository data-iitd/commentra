package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare two string variables s and t to store user input.
	var s, t string

	// Read user input and store it in variables s and t respectively.
	fmt.Scan(&s, &t)

	// Concatenate the string s with itself and store the result back in s.
	s += s

	// Check if the substring t is present in the string s. If it is, print "Yes". Otherwise, print "No".
	if strings.Contains(s, t) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>

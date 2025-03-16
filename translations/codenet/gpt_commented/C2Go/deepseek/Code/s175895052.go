package main

import (
	"fmt"
)

func main() {
	// Declare a string to hold the input string
	var n string

	// Read a string from standard input and store it in the variable 'n'
	fmt.Scan(&n)

	// Check if the first three characters are the same or if the last three characters are the same
	if len(n) >= 4 && (n[0] == n[1] && n[1] == n[2] || n[1] == n[2] && n[2] == n[3]) {
		// If the condition is true, print "Yes"
		fmt.Println("Yes")
	} else {
		// If the condition is false, print "No"
		fmt.Println("No")
	}
}


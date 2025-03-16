package main

import (
	"fmt"
)

func main() {
	// Read an integer input from the user
	var n int
	fmt.Scan(&n)

	// Read a string input from the user
	var s string
	fmt.Scan(&s)

	// Check if the length of the string is odd
	if n%2 != 0 {
		// If the length is odd, print 'No' since it cannot be split into two equal halves
		fmt.Println("No")
	} else {
		// Check if the first half of the string is equal to the second half
		if s[:n/2] == s[n/2:] {
			// If both halves are equal, print 'Yes'
			fmt.Println("Yes")
		} else {
			// If the halves are not equal, print 'No'
			fmt.Println("No")
		}
	}
}

// <END-OF-CODE>

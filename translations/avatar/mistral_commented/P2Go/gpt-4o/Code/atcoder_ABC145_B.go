package main

import (
	"fmt"
)

func main() {
	// Read an integer value from the user
	var n int
	fmt.Scan(&n)

	// Read a string value from the user
	var s string
	fmt.Scan(&s)

	// Check if n is odd
	if n%2 != 0 {
		fmt.Println("No")
	} else if s[:n/2] == s[n/2:] {
		// Check if the first half of the string is equal to the second half
		fmt.Println("Yes")
	} else {
		// If the first half is not equal to the second half, print 'No'
		fmt.Println("No")
	}
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take an integer input from the user
	var n int
	fmt.Scan(&n)

	// Take a string input from the user
	var s string
	fmt.Scan(&s)

	// Check if n is odd
	if n%2 != 0 {
		// Print 'No' if n is odd
		fmt.Println("No")
	} else {
		// If n is even, compare the first half of the string with the second half
		if strings.Compare(s[:n/2], s[n/2:]) == 0 {
			// Print 'Yes' if the first half is equal to the second half
			fmt.Println("Yes")
		} else {
			// Print 'No' if the first half is not equal to the second half
			fmt.Println("No")
		}
	}
}


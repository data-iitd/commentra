package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a character array to hold the input string
	s := make([]byte, 1000)

	// Read a string from standard input
	fmt.Scanf("%s", &s)

	// Initialize variables: i for iteration and flag to track validity
	i, flag := 0, 0

	// Iterate through each character in the string
	for i < len(s) {
		// Check if the index is even
		if i%2 == 0 {
			// Switch case for characters at even indices
			switch s[i] {
			case 'R':
				// 'R' is valid, do nothing
			case 'U':
				// 'U' is valid, do nothing
			case 'D':
				// 'D' is valid, do nothing
			default:
				// If character is not valid, set flag to indicate an error
				flag = 1
			}
		} else {
			// Switch case for characters at odd indices
			switch s[i] {
			case 'L':
				// 'L' is valid, do nothing
			case 'U':
				// 'U' is valid, do nothing
			case 'D':
				// 'D' is valid, do nothing
			default:
				// If character is not valid, set flag to indicate an error
				flag = 1
			}
		}
		i++
	}

	// Check the flag to determine if the input string was valid
	if flag == 0 {
		// If flag is still 0, print "Yes" indicating valid input
		fmt.Println("Yes")
	} else {
		// If flag is set, print "No" indicating invalid input
		fmt.Println("No")
	}
}


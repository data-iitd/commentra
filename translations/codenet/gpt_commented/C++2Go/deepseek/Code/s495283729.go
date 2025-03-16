package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a string to hold the input string
	var s string
	
	// Read a string from standard input
	fmt.Scanln(&s)
	
	// Initialize variables: i for iteration and flag to track validity
	var flag bool = false
	
	// Iterate through each character in the string
	for i := 0; i < len(s); i++ {
		// Check if the index is even
		if i % 2 == 0 {
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
				flag = true
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
				flag = true
			}
		}
	}
	
	// Check the flag to determine if the input string was valid
	if flag == false {
		// If flag is still false, print "Yes" indicating valid input
		fmt.Println("Yes")
	} else {
		// If flag is set, print "No" indicating invalid input
		fmt.Println("No")
	}
}

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare a string to hold the input string
	var s string

	// Read a string from standard input
	fmt.Scanf("%s", &s)

	// Initialize variables: i for iteration and flag to track validity
	var i, flag int

	// Iterate through each character in the string
	for i = 0; i < len(s); i++ {
		// Check if the index is even
		if i%2 == 0 {
			// Switch case for characters at even indices
			switch s[i] {
			case 'R':
				// 'R' is valid, do nothing
				break
			case 'U':
				// 'U' is valid, do nothing
				break
			case 'D':
				// 'D' is valid, do nothing
				break
			default:
				// If character is not valid, set flag to indicate an error
				flag = 1
				break
			}
		} else {
			// Switch case for characters at odd indices
			switch s[i] {
			case 'L':
				// 'L' is valid, do nothing
				break
			case 'U':
				// 'U' is valid, do nothing
				break
			case 'D':
				// 'D' is valid, do nothing
				break
			default:
				// If character is not valid, set flag to indicate an error
				flag = 1
				break
			}
		}
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


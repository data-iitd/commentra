package main

import (
	"fmt"
)

func main() {
	// Creating a variable to read input from the console
	var str string
	var k int64

	// Reading a string input from the user
	fmt.Scan(&str)

	// Reading a long integer input from the user
	fmt.Scan(&k)

	// Getting the length of the input string
	n := len(str)

	// Looping through the first k characters of the string
	for i := int64(0); i < k; i++ {
		// Checking if the current character is '1'
		if str[i] == '1' {
			// If it's the last character in the range, print 1 and exit
			if i == k-1 {
				fmt.Println(1)
				return // Exit the program
			}
		} else {
			// If the current character is not '1', print it and exit
			fmt.Println(string(str[i]))
			return // Exit the program
		}
	}
}

// <END-OF-CODE>

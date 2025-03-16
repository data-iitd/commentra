package main

import (
	"fmt"
)

func main() {
	var str string
	var k int64

	// Step 1: Read input from the user
	fmt.Scan(&str) // Step 2: Read the input string
	fmt.Scan(&k)   // Step 4: Read the value of k

	c := []rune(str) // Step 3: Convert the string to a character array
	n := len(c)      // Step 5: Initialize the length of the string

	for i := int64(0); i < k; i++ { // Step 6: Loop through the character array k times
		if c[i] == '1' { // Step 7: Check if the character at the current index is '1'
			if i == k-1 { // Step 8: Check if the current index is the last index
				fmt.Println(1) // Step 9: Print '1' and return
				return
			}
		} else { // Step 10: If it is not '1'
			fmt.Println(string(c[i])) // Step 11: Print the character and return
			return
		}
	}
}

// <END-OF-CODE>

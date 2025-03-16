package main

import (
	"fmt"
)

func main() {
	// Declaring variables
	var n, i, j, p int
	p = 97 // 'p' is initialized to 97, which is the ASCII value for 'a'

	// Reading an integer input from the console
	fmt.Scan(&n)

	// Creating a character array of size 'n'
	c := make([]byte, n)

	// Filling the character array with letters starting from 'a' (ASCII 97)
	for i = 0; i < 4; i++ { // Looping through the first 4 positions
		for j = i; j < n; j += 4 { // Filling every 4th position starting from 'i'
			c[j] = byte(p) // Assigning the character corresponding to ASCII value 'p'
			p++ // Incrementing 'p' to get the next character
		}
	}

	// Printing the filled character array to the console
	for i = 0; i < n; i++ {
		fmt.Print(string(c[i])) // Outputting each character in the array
	}
}

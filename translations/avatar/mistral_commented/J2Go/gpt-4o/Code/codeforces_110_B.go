package main

import (
	"fmt"
)

func main() {
	var n int // Declare an integer variable `n` to store the size of the character array
	var p rune = 'a' // Declare a rune variable `p` to store the current character to be added to the array

	fmt.Scan(&n) // Read an integer `n` from the standard input

	c := make([]rune, n) // Create a new slice of runes `c` of size `n`

	for i := 0; i < 4; i++ { // Use a for loop to iterate through the first four elements of the array
		for j := i; j < n; j += 4 { // Use a nested for loop to populate every fourth element of the array with the next character
			c[j] = p // Set the current element of the array to the current character
			p++ // Increment the character to be added to the next element
		}
	}

	for i := 0; i < n; i++ { // Use a for loop to print each character in the array to the standard output
		fmt.Print(string(c[i])) // Convert rune to string for printing
	}

	// No need to close anything in Go for standard input
}

// <END-OF-CODE>

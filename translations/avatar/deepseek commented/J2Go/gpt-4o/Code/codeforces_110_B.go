package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the size of the array from the user
	c := make([]rune, n) // Initialize the character slice of size n

	p := 97 // Starting ASCII value for 'a'
	// Nested loops to assign characters to the slice
	for i := 0; i < 4; i++ {
		for j := i; j < n; j += 4 {
			c[j] = rune(p) // Assign character and increment ASCII value
		}
		p++ // Increment the ASCII value for the next character
	}

	// Print the character slice to the console
	for i := 0; i < n; i++ {
		fmt.Print(string(c[i]))
	}
}

// <END-OF-CODE>

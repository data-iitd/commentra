// Package declaration
package main

import "fmt"
// Importing the 'fmt' package for input/output operations

func main() {
	// Variable declaration and initialization
	var n int
	var s string

	// Reading input from the user
	fmt.Scan(&n, &s)

	// Variable declaration and initialization for maximum count and current count
	var max int
	var cnt int

	// Iterating through each character in the string 's'
	for _, r := range s {
		// Checking if the character is 'I'
		if r == 'I' {
			// Incrementing the current count
			cnt++
		} else {
			// Decrementing the current count
			cnt--
		}

		// Updating the maximum count if the current count is greater
		if cnt > max {
			max = cnt
		}
	}

	// Printing the maximum count
	fmt.Println(max)

// End of the code
}
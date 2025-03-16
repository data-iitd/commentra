package main

import (
	"fmt" // Import the format package for formatted I/O
)

func main() {
	var a, b, c, i, count int // Declare variables a, b, c, i, and count
	fmt.Scan(&a, &b, &c) // Read three integers a, b, and c from the standard input
	count = 0 // Initialize the count variable to zero

	// The following for loop iterates from the value of 'a' to the value of 'b'
	for i = a; i <= b; i++ {
		// Check if 'c' is divisible by 'i'
		if c % i == 0 {
			// If it is, increment the count variable
			count++
		}
	}

	// Print the value of 'count' to the standard output
	fmt.Println(count)
}


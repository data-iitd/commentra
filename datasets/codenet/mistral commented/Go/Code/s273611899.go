// Package main is the entry point of the program
package main

import (
	// Importing the 'fmt' package for input/output operations
	"fmt"
)

// Function main is the entry point of the program
func main() {
	// Declaring two integer variables 'n' and 'x'
	var n, x int

	// Loop infinitely until user inputs 0 for both 'n' and 'x'
	for {
		// Read user input for 'n' and 'x'
		fmt.Scan(&n, &x)

		// Check if user has entered 0 for both 'n' and 'x' to break the loop
		if n == 0 && x == 0 {
			break
		}

		// Declaring an integer variable 'c' to store the count of triples
		var c int

		// Inner loop to find triples that sum up to 'x'
		for i := 1; i <= n-2; i++ {
			// Inner loop to compare 'j' with all the remaining numbers
			for j := i + 1; j <= n-1; j++ {
				// Inner loop to compare 'k' with all the remaining numbers
				for k := j + 1; k <= n; k++ {
					// Check if the sum of 'i', 'j', and 'k' equals 'x'
					if i+j+k == x {
						// Increment the count 'c' if the condition is true
						c++
					}
				}
			}
		}

		// Print the count of triples that sum up to 'x'
		fmt.Println(c)
	}

// End of the code
}
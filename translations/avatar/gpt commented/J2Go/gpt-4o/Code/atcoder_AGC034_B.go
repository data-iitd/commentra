package main

import (
	"fmt"
	"strings"
)

func main() {
	// Create a scanner for reading input
	var input string
	fmt.Scan(&input)

	// Create an instance of the BABC struct to solve the problem
	solver := BABC{}
	
	// Call the solve method with the input string
	solver.solve(input)
}

type BABC struct{}

func (b *BABC) solve(s string) {
	// Replace occurrences of "BC" with "D"
	s = strings.ReplaceAll(s, "BC", "D")

	// Initialize counters for 'A' and the result
	var cnt, tmp int64

	// Iterate through the modified string to count occurrences
	for _, char := range s {
		// Increment temporary counter for 'A'
		if char == 'A' {
			tmp++
		} else if char == 'D' {
			// Add the count of 'A's to the result when 'D' is encountered
			cnt += tmp
		} else {
			// Reset the temporary counter for any other character
			tmp = 0
		}
	}

	// Output the final count of valid pairs
	fmt.Println(cnt)
}

// <END-OF-CODE>

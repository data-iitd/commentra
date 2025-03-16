package main

import (
	"fmt"
	"strings"
)

func main() {
	// Main function that starts the program

	var input string
	fmt.Scan(&input) // Read input from the console

	solver := BABC{} // Create a new instance of the BABC struct
	solver.solve(input) // Solve the problem and print the result
}

type BABC struct {
	// Struct for solving the problem
}

func (b *BABC) solve(s string) {
	// Method for solving the problem

	s = strings.ReplaceAll(s, "BC", "D") // Replace all occurrences of "BC" with "D" in the input string

	cnt := int64(0) // Initialize counter for the number of "D"s
	tmp := int64(0) // Initialize temporary variable for counting consecutive "A"s

	for _, char := range s {
		// Loop through each character in the string
		if char == 'A' {
			// If the character is "A", increment the temporary counter
			tmp++
		} else if char == 'D' {
			// If the character is "D", add the temporary counter to the total count
			cnt += tmp
		} else {
			// If the character is neither "A" nor "D", reset the temporary counter
			tmp = 0
		}
	}

	// Print the result
	fmt.Println(cnt)
}

// <END-OF-CODE>

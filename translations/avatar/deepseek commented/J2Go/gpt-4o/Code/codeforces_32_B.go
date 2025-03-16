package main

import (
	"fmt"
)

func main() {
	var input string
	fmt.Scan(&input) // Read the input string

	s := false // Initialize a boolean variable to keep track of the state

	// Process each character in the input string
	for i := 0; i < len(input); i++ {
		if input[i] == '.' { // Check if the current character is a dot
			if s { // If the state is true
				fmt.Print(1) // Print '1' and reset the state to false
				s = false
			} else { // If the state is false
				fmt.Print(0) // Print '0' and set the state to false
				s = false
			}
		} else { // If the current character is not a dot
			if s { // If the state is true
				fmt.Print(2) // Print '2' and reset the state to false
				s = false
			} else { // If the state is false
				s = true // Set the state to true
			}
		}
	}
}

// <END-OF-CODE>

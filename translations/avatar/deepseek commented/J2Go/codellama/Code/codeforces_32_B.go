package main

import (
	"fmt"
	"os"
)

func main() {
	// Initialize a Scanner object to read input from the user
	in := bufio.NewScanner(os.Stdin)
	// Read the input string and convert it to a character array
	n := in.Text()
	// Initialize a boolean variable to keep track of the state
	s := false

	// Process each character in the character array
	for i := 0; i < len(n); i++ {
		if n[i] == '.' { // Check if the current character is a dot
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
	in.Close() // Close the Scanner object
}


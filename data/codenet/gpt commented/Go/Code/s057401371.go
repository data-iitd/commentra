package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new scanner to read input from standard input (os.Stdin)
	sc := bufio.NewScanner(os.Stdin)
	
	// Read the next line of input
	sc.Scan()
	// Store the input text in variable 's'
	s := sc.Text()

	// Calculate the difference between lowercase and uppercase letters
	d := 'a' - 'A'
	
	// Iterate over each rune (character) in the input string
	for _, r := range s {
		// Initialize a variable to hold the modified character
		rr := r
		
		// Check if the character is an uppercase letter
		if 'A' <= r && r <= 'Z' {
			// Convert uppercase to lowercase by adding the difference
			rr = r + d
		} else if 'a' <= r && r <= 'z' {
			// Convert lowercase to uppercase by subtracting the difference
			rr = r - d
		}
		
		// Print the modified character
		fmt.Printf("%c", rr)
	}
	
	// Print a newline at the end of the output
	fmt.Println()
}

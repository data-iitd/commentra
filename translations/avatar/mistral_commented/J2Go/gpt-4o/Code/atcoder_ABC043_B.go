package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin) // Initialize scanner for reading input
	solver := BUnhappyHackingABCEdit{}      // Initialize the solver

	if scanner.Scan() { // Read the input string
		s := scanner.Text()
		solver.solve(s) // Run the solver with the input string
	}
}

// BUnhappyHackingABCEdit struct for solving the problem
type BUnhappyHackingABCEdit struct{}

// solve method to process the input string
func (b *BUnhappyHackingABCEdit) solve(s string) {
	var d strings.Builder // Initialize a strings.Builder for the output

	for _, c := range s { // Iterate through each character in the input string
		switch c { // Switch statement to handle different characters
		case '0':
			d.WriteString("0") // Append "0" to the output strings.Builder
		case '1':
			d.WriteString("1") // Append "1" to the output strings.Builder
		case 'B':
			if d.Len() > 0 { // If there is a character in the output strings.Builder
				d.Truncate(d.Len() - 1) // Remove the last character from the output strings.Builder
			}
		}
	}

	fmt.Println(d.String()) // Print the output strings.Builder to the console
}

// <END-OF-CODE>

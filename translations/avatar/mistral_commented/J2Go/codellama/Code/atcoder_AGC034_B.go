
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Main method that starts the program

	inputStream := os.Stdin // Input stream for reading from the console
	outputStream := os.Stdout // Output stream for writing to the console
	in := bufio.NewScanner(inputStream) // Create a new scanner for reading input
	out := bufio.NewWriter(outputStream) // Create a new writer for writing output

	solver := BABC{} // Create a new instance of the BABC class
	solver.solve(1, in, out) // Solve the problem and print the result

	out.Flush() // Flush the output buffer
}

type BABC struct {
	// Inner class for solving the problem
}

func (solver *BABC) solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	// Method for solving the problem

	s := in.Text() // Read the input string
	s = strings.ReplaceAll(s, "BC", "D") // Replace all occurrences of "BC" with "D" in the input string

	cnt := 0 // Initialize counter for the number of "D"s
	tmp := 0 // Initialize temporary variable for counting consecutive "A"s

	for i := 0; i < len(s); i++ {
		// Loop through each character in the string

		if s[i] == 'A' {
			// If the character is "A", increment the temporary counter
			tmp++
		} else if s[i] == 'D' {
			// If the character is "D", add the temporary counter to the total count
			cnt += tmp
		} else {
			// If the character is neither "A" nor "D", reset the temporary counter
			tmp = 0
		}
	}

	// Print the result
	fmt.Fprintln(out, cnt)
}


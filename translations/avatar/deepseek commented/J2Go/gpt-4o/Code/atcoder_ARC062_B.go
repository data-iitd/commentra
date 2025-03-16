package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Main function to run the program
func main() {
	reader := bufio.NewReader(os.Stdin) // Create a buffered reader for input
	writer := bufio.NewWriter(os.Stdout) // Create a buffered writer for output
	defer writer.Flush() // Ensure the writer is flushed at the end

	solver := TaskD{} // Create an instance of TaskD
	solver.Solve(reader, writer) // Call the Solve method of TaskD
}

// TaskD struct contains the Solve method which calculates a score based on the input string
type TaskD struct{}

// Solve method takes a reader and a writer
func (t *TaskD) Solve(reader *bufio.Reader, writer *bufio.Writer) {
	S, _ := reader.ReadString('\n') // Read the next string from the input
	S = strings.TrimSpace(S) // Trim any whitespace from the input
	score := 0 // Initialize the score to 0

	// Iterate through each character in the string S
	for i, char := range S {
		var my rune
		if i%2 == 0 {
			my = 'g' // Determine the expected character based on the index
		} else {
			my = 'p'
		}
		his := char // Get the character at the current index in S

		// Compare the expected character with the actual character and update the score
		if my != his {
			if my == 'p' {
				score++ // Update the score based on the expected character
			} else {
				score-- // Update the score based on the expected character
			}
		}
	}
	fmt.Fprintln(writer, score) // Print the final score
}

// <END-OF-CODE>

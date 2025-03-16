package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Create an instance of TaskD to solve the problem
	solver := TaskD{}

	// Call the solve method with test number, input reader, and output writer
	solver.solve(1, reader, writer)

	// Close the writer to flush the output
	writer.Flush()
}

type TaskD struct {
}

func (t *TaskD) solve(testNumber int, reader *bufio.Reader, writer *bufio.Writer) {
	// Read the input string S
	S := readString(reader)
	score := 0 // Initialize score to zero

	// Iterate through each character in the string S
	for i := 0; i < len(S); i++ {
		// Determine the character for'my' based on the index (even or odd)
		my := 'g'
		if i%2 == 1 {
			my = 'p'
		}

		// Get the character from the input string at the current index
		his := S[i]

		// Compare'my' and 'his' characters to update the score
		if my!= his {
			// Increment score if'my' is 'p', otherwise decrement
			if my == 'p' {
				score++
			} else {
				score--
			}
		}
	}

	// Output the final score
	fmt.Fprintln(writer, score)
}

func readString(reader *bufio.Reader) string {
	// Read a line and return it as a string
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	return strings.TrimSpace(line)
}


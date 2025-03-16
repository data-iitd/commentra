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

	// Create an instance of TaskB and solve the problem
	solver := TaskB{}
	solver.solve(1, reader, writer)

	// Close the output stream
	writer.Flush()
}

type TaskB struct {
}

func (t *TaskB) solve(testNumber int, reader *bufio.Reader, writer *bufio.Writer) {
	// Read the input string
	x, _ := reader.ReadString('\n')
	x = strings.TrimSpace(x)

	// Initialize a stack
	s := make([]rune, 0)
	c := 0 // Counter for pairs of '0' and '1'

	// Iterate through each character in the input string
	for _, ch := range x {
		// Push the current character onto the stack
		s = append(s, ch)

		// Process the stack while there are at least two characters
		for len(s) > 1 {
			p := s[len(s)-1]
			s = s[:len(s)-1]
			q := s[len(s)-1]
			s = s[:len(s)-1]

			// Check if the characters form a pair of '0' and '1'
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++ // Increment the counter for valid pairs
				continue
			} else {
				// If not a valid pair, push the characters back onto the stack
				s = append(s, q)
				s = append(s, p)
				break
			}
		}
	}

	// Output the result, which is twice the count of pairs found
	fmt.Fprintln(writer, c*2)
}


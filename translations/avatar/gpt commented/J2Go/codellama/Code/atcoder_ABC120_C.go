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
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := bufio.NewScanner(inputStream)
	out := bufio.NewWriter(outputStream)

	// Create an instance of TaskB and solve the problem
	solver := TaskB{}
	solver.solve(1, in, out)

	// Close the output stream
	out.Flush()
}

type TaskB struct{}

func (solver *TaskB) solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	// Read the input string
	x := in.Text()
	s := make([]rune, 0)
	c := 0 // Counter for pairs of '0' and '1'

	// Iterate through each character in the input string
	for i := 0; i < len(x); i++ {
		// Push the current character onto the stack
		s = append(s, rune(x[i]))

		// Process the stack while there are at least two characters
		for len(s) > 1 {
			p := s[len(s)-1] // Pop the top character
			q := s[len(s)-2] // Pop the next character
			s = s[:len(s)-2]

			// Check if the characters form a pair of '0' and '1'
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++ // Increment the counter for valid pairs
				continue // Continue to check for more pairs
			} else {
				// If not a valid pair, push the characters back onto the stack
				s = append(s, q)
				s = append(s, p)
				break // Exit the while loop
			}
		}
	}
	// Output the result, which is twice the count of pairs found
	fmt.Fprintln(out, c*2)
}

// 
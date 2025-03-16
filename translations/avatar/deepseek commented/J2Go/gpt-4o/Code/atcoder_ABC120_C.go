package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new input reader
	in := bufio.NewReader(os.Stdin)
	// Create a new output writer
	out := bufio.NewWriter(os.Stdout)
	// Create an instance of TaskB and call its solve method
	solver := TaskB{}
	solver.solve(in, out)
	// Flush the output writer to ensure all output is written
	out.Flush()
}

// TaskB struct contains the main logic of the program
type TaskB struct{}

// The solve method implements the main logic
func (t *TaskB) solve(in *bufio.Reader, out *bufio.Writer) {
	// Read the input string
	x, _ := in.ReadString('\n')
	x = x[:len(x)-1] // Remove the newline character

	// Initialize a stack to keep track of characters
	stack := []rune{}
	// Initialize a counter to count balanced pairs
	c := 0

	// Iterate through each character in the input string
	for _, char := range x {
		// Push the current character onto the stack
		stack = append(stack, char)

		// While the stack has more than one element, check for balanced pairs
		for len(stack) > 1 {
			// Pop the top two elements from the stack
			p := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			q := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			// Check if they form a balanced pair
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				// Increment the counter if a balanced pair is found
				c++
				continue
			} else {
				// If not a balanced pair, push the popped elements back onto the stack
				stack = append(stack, q)
				stack = append(stack, p)
				break
			}
		}
	}

	// Output the result, which is twice the counter value
	fmt.Fprintln(out, c*2)
}

// Helper function to read the next token from the input stream
func next(in *bufio.Reader) string {
	var token string
	fmt.Fscan(in, &token)
	return token
}

// <END-OF-CODE>

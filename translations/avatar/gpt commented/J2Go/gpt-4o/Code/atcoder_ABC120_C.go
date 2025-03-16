package main

import (
	"bufio"
	"fmt"
	"os"
)

type TaskB struct{}

func (t *TaskB) solve(x string) int {
	stack := []rune{}
	c := 0 // Counter for pairs of '0' and '1'

	// Iterate through each character in the input string
	for _, char := range x {
		// Push the current character onto the stack
		stack = append(stack, char)

		// Process the stack while there are at least two characters
		for len(stack) > 1 {
			p := stack[len(stack)-1] // Pop the top character
			stack = stack[:len(stack)-1]
			q := stack[len(stack)-1] // Pop the next character
			stack = stack[:len(stack)-1]

			// Check if the characters form a pair of '0' and '1'
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++ // Increment the counter for valid pairs
				continue // Continue to check for more pairs
			} else {
				// If not a valid pair, push the characters back onto the stack
				stack = append(stack, q)
				stack = append(stack, p)
				break // Exit the while loop
			}
		}
	}
	// Return the result, which is twice the count of pairs found
	return c * 2
}

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the input string
	x, _ := reader.ReadString('\n')
	x = x[:len(x)-1] // Remove the newline character

	// Create an instance of TaskB and solve the problem
	solver := TaskB{}
	result := solver.solve(x)

	// Output the result
	fmt.Fprintln(writer, result)
	writer.Flush()
}

// <END-OF-CODE>

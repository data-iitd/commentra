package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin) // Creating a buffered reader for input
	out := bufio.NewWriter(os.Stdout) // Creating a buffered writer for output
	defer out.Flush() // Ensure the output is flushed at the end

	var t int
	fmt.Fscan(in, &t) // Read the number of test cases

	for i := 0; i < t; i++ {
		solve(in, out) // Call the solve function for each test case
	}
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var x string
	fmt.Fscan(in, &x) // Reading the input string

	stack := []rune{} // Stack to store characters
	c := 0            // Counter to store the number of pairs

	// Iterating through each character in the input string
	for _, char := range x {
		stack = append(stack, char) // Pushing the character onto the stack

		// Popping two characters from the stack and checking for a pair
		for len(stack) > 1 {
			p := stack[len(stack)-1] // Popping the top character
			stack = stack[:len(stack)-1] // Remove the top character

			q := stack[len(stack)-1] // Popping the second top character
			stack = stack[:len(stack)-1] // Remove the second top character

			// If the popped characters form a pair, increment the counter and continue
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++
				continue
			}

			// If the characters don't form a pair, push them back onto the stack and break
			stack = append(stack, q)
			stack = append(stack, p)
			break
		}
	}

	// Writing the output to the buffered writer
	fmt.Fprintln(out, c*2)
}

// Note: The InputReader class is not needed in Go as we use bufio.Reader directly.

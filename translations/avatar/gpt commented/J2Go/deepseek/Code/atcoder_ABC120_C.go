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
	defer writer.Flush()

	// Read the input string
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	// Create a stack to hold characters
	var stack []rune
	count := 0

	// Iterate through each character in the input string
	for _, char := range input {
		// Push the current character onto the stack
		stack = append(stack, char)

		// Process the stack while there are at least two characters
		for len(stack) > 1 {
			// Pop the top character
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			// Pop the next character
			next := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			// Check if the characters form a pair of '0' and '1'
			if (top == '1' && next == '0') || (top == '0' && next == '1') {
				count++ // Increment the counter for valid pairs
				continue  // Continue to check for more pairs
			} else {
				// If not a valid pair, push the characters back onto the stack
				stack = append(stack, next)
				stack = append(stack, top)
				break // Exit the loop
			}
		}
	}

	// Output the result, which is twice the count of pairs found
	fmt.Println(count * 2)
}

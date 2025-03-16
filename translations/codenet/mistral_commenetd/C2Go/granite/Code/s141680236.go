

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize stack top and array kinbo
var top int = 0
var kinbo [1000]int

func push(chonda int) {
	// Increment top and push element chonda into kinbo array
	top++
	kinbo[top] = chonda
}

func pop() int {
	// Decrement top and return the top element
	top--
	return kinbo[top+1]
}

func main() {
	var chonda, yamagami int // Initialize variables chonda and yamagami

	// Initialize stack top to 0
	top = 0

	scanner := bufio.NewScanner(os.Stdin)

	// Read input strings from standard input until EOF is reached
	for scanner.Scan() {
		input := scanner.Text()

		// Check if the first character of the input string is '+'
		if input[0] == '+' {
			// Pop two elements from the stack
			chonda = pop()
			yamagami = pop()

			// Add the popped elements and push the result onto the stack
			push(chonda + yamagami)
		}
		// Check if the first character of the input string is '-'
		else if input[0] == '-' {
			// Pop two elements from the stack
			yamagami = pop()
			chonda = pop()

			// Subtract the second popped element from the first popped element and push the result onto the stack
			push(chonda - yamagami)
		}
		// Check if the first character of the input string is '*'
		else if input[0] == '*' {
			// Pop two elements from the stack
			chonda = pop()
			yamagami = pop()

			// Multiply the popped elements and push the result onto the stack
			push(chonda * yamagami)
		}
		// If the first character of the input string is not an operator, convert it to an integer and push it onto the stack
		else {
			num, _ := strconv.Atoi(input)
			push(num)
		}
	}

	// Print the top element of the stack, which is the final result
	fmt.Println(pop())
}


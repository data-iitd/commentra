package main

import (
	"fmt"
	"os"
	"strconv"
)

// Global variables for stack and top index
var top int
var kinbo [1000]int

// Function to push a value onto the stack
func push(value int) {
	top++
	kinbo[top] = value
}

// Function to pop a value from the stack
func pop() int {
	value := kinbo[top]
	top--
	return value
}

func main() {
	// Initialize the top index of the stack
	top = 0

	// Read input until end of file
	var input string
	for {
		_, err := fmt.Scan(&input)
		if err != nil {
			break
		}

		// Check the operation based on the first character of the input
		switch input[0] {
		case '+':
			// Pop two values, add them, and push the result
			chonda := pop()
			yamagami := pop()
			push(chonda + yamagami)
		case '-':
			// Pop two values, subtract the second from the first, and push the result
			yamagami := pop()
			chonda := pop()
			push(chonda - yamagami)
		case '*':
			// Pop two values, multiply them, and push the result
			chonda := pop()
			yamagami := pop()
			push(chonda * yamagami)
		default:
			// Convert input to integer and push it onto the stack
			value, _ := strconv.Atoi(input)
			push(value)
		}
	}

	// Print the final result from the stack
	fmt.Println(pop())
}

// <END-OF-CODE>

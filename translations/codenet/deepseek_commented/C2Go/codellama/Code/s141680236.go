package main

import (
	"fmt"
	"strconv"
)

// Function declarations for stack operations
func push(chonda int)

// Global variables for stack and top index
var top int
var kinbo [1000]int

func main() {
	// Variables to store input values
	var chonda, yamagami int

	// Initialize the top index of the stack
	top = 0

	// Array to store input characters temporarily
	var null [100]string

	// Read input until end of file
	for {
		// Check the operation based on the first character of the input
		if null[0] == "+" {
			// Pop two values, add them, and push the result
			chonda = pop()
			yamagami = pop()
			push(chonda + yamagami)
		} else if null[0] == "-" {
			// Pop two values, subtract the second from the first, and push the result
			yamagami = pop()
			chonda = pop()
			push(chonda - yamagami)
		} else if null[0] == "*" {
			// Pop two values, multiply them, and push the result
			chonda = pop()
			yamagami = pop()
			push(chonda * yamagami)
		} else {
			// Convert input to integer and push it onto the stack
			push(strconv.Atoi(null[0]))
		}
	}

	// Print the final result from the stack
	fmt.Println(pop())
}

// Function to push a value onto the stack
func push(chonda int) {
	kinbo[top] = chonda
	top++
}

// Function to pop a value from the stack
func pop() int {
	top--
	return kinbo[top]
}


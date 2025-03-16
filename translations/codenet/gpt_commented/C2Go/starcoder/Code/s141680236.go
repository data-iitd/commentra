package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function prototypes for stack operations
func push(chonda int) {
}

func pop() int {
	return 0
}

// Global variables for stack management
var top int = 0
var kinbo [1000]int

func main() {
	var chonda, yamagami int
	var null string
	var input string

	// Read input until EOF
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		input = scanner.Text()

		// If the input is a '+' operator, perform addition
		if input[0] == '+' {
			chonda = pop() // Pop the top two values from the stack
			yamagami = pop()
			push(chonda + yamagami) // Push the result of addition back onto the stack
		}
		// If the input is a '-' operator, perform subtraction
		else if input[0] == '-' {
			yamagami = pop() // Pop the top two values from the stack
			chonda = pop()
			push(chonda - yamagami) // Push the result of subtraction back onto the stack
		}
		// If the input is a '*' operator, perform multiplication
		else if input[0] == '*' {
			chonda = pop() // Pop the top two values from the stack
			yamagami = pop()
			push(chonda * yamagami) // Push the result of multiplication back onto the stack
		}
		// If the input is a number, convert it to an integer and push onto the stack
		else {
			push(atoi(input))
		}
	}

	// Pop and print the final result from the stack
	fmt.Printf("%d\n", pop())
}

// Function to push an integer onto the stack
func push(chonda int) {
	kinbo[top] = chonda
	top++
}

// Function to pop an integer from the stack
func pop() int {
	top--
	return kinbo[top]
}


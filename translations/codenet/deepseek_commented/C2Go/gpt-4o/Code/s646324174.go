package main

import (
	"fmt"
	"os"
	"strconv"
)

// Define the stack and top variable
var top int
var S [10000]int

// Function to push an element onto the stack
func push(x int) {
	S[top] = x
	top++
}

// Function to pop an element from the stack
func pop() int {
	top--
	return S[top]
}

// Main function to read input, perform operations, and print the result
func main() {
	var a, b int
	var s string
	top = 0 // Initialize the top of the stack

	// Read input until end of file
	for {
		_, err := fmt.Scan(&s)
		if err != nil {
			break // Exit on error (EOF)
		}
		switch s[0] {
		case '+':
			// Pop two elements, add them, and push the result
			b = pop()
			a = pop()
			push(a + b)
		case '-':
			// Pop two elements, subtract the top element from the bottom element, and push the result
			b = pop()
			a = pop()
			push(a - b)
		case '*':
			// Pop two elements, multiply them, and push the result
			b = pop()
			a = pop()
			push(a * b)
		default:
			// Convert the input string to an integer and push it onto the stack
			num, _ := strconv.Atoi(s)
			push(num)
		}
	}
	// Print the final result from the stack
	fmt.Println(pop())
}

// <END-OF-CODE>

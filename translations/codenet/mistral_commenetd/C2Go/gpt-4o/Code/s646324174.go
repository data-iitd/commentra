package main

import (
	"fmt"
	"os"
	"strconv"
)

// Initialize stack top to 0
var top int
var S [10000]int

// Function to push an element onto the stack
func push(x int) {
	// Increment the top index and push the element
	top++
	S[top] = x
}

// Function to pop an element from the stack
func pop() int {
	// Return the top element and decrement the top index
	result := S[top]
	top--
	return result
}

// Main function
func main() {
	// Initialize variables
	var a, b int
	var s string

	// Initialize stack top to 0
	top = 0

	// Read input until end of file
	for {
		_, err := fmt.Scan(&s)
		if err != nil {
			break // Exit on EOF or error
		}

		// Check if the input is an operator or a number
		if s == "+" || s == "-" || s == "*" {
			// Pop the top two elements from the stack
			b = pop()
			a = pop()

			// Perform the operation and push the result back onto the stack
			switch s {
			case "+":
				push(a + b)
			case "-":
				push(a - b)
			case "*":
				push(a * b)
			}
		} else { // Input is a number
			// Convert string to integer and push the number directly onto the stack
			num, _ := strconv.Atoi(s)
			push(num)
		}
	}

	// Print the final result
	fmt.Println(pop())
}

// <END-OF-CODE>

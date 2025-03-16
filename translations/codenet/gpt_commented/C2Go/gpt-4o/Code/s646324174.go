package main

import (
	"fmt"
	"os"
	"strconv"
)

// Global variables
var top int
var S [10000]int // Stack to hold integers

// Function to push an integer onto the stack
func push(x int) {
	S[top] = x // Assign the value to the stack
	top++      // Increment top
}

// Function to pop an integer from the stack
func pop() int {
	top--      // Decrement the top index
	return S[top] // Return the top value
}

func main() {
	var a, b int // Variables to hold the operands for operations
	var s string // Variable to hold the input string
	top = 0     // Initialize the stack top index

	// Read input until EOF
	for {
		_, err := fmt.Scan(&s)
		if err != nil {
			break // Exit on EOF or error
		}

		// Check for addition operation
		if s == "+" {
			b = pop() // Pop the top two values from the stack
			a = pop()
			push(a + b) // Push the result of addition back onto the stack
		} else if s == "-" { // Check for subtraction operation
			b = pop() // Pop the top two values from the stack
			a = pop()
			push(a - b) // Push the result of subtraction back onto the stack
		} else if s == "*" { // Check for multiplication operation
			b = pop() // Pop the top two values from the stack
			a = pop()
			push(a * b) // Push the result of multiplication back onto the stack
		} else { // If the input is a number
			num, _ := strconv.Atoi(s) // Convert string to integer
			push(num) // Push onto the stack
		}
	}

	// Print the final result which is the last remaining value in the stack
	fmt.Println(pop())
}

// <END-OF-CODE>

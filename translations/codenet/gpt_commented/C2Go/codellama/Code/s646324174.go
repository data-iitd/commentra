package main

import (
	"fmt"
	"strconv"
)

// Global variables
var top int = 0 // Stack to hold integers and a variable to track the top index
var S [10000]int

// Function to push an integer onto the stack
func push(x int) {
	S[top] = x // Increment top and assign the value to the stack
	top++
}

// Function to pop an integer from the stack
func pop() int {
	top--
	return S[top] // Return the top value and decrement the top index
}

func main() {
	var a, b int // Variables to hold the operands for operations
	var s string // Array to hold the input string

	// Read input until EOF
	for {
		fmt.Scan(&s)
		if s == "+" {
			b = pop() // Pop the top two values from the stack
			a = pop()
			push(a + b) // Push the result of addition back onto the stack
		} else if s == "-" {
			b = pop() // Pop the top two values from the stack
			a = pop()
			push(a - b) // Push the result of subtraction back onto the stack
		} else if s == "*" {
			b = pop() // Pop the top two values from the stack
			a = pop()
			push(a * b) // Push the result of multiplication back onto the stack
		} else {
			push(strconv.Atoi(s)) // Convert string to integer and push onto the stack
		}
	}

	// Print the final result which is the last remaining value in the stack
	fmt.Println(pop())
}


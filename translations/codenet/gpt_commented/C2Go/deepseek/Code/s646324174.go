package main

import (
	"fmt"
	"os"
	"strconv"
)

// Global variables
var top int
var S [10000]int // Stack to hold integers and a variable to track the top index

// Function to push an integer onto the stack
func push(x int) {
	S[top] = x
	top++
}

// Function to pop an integer from the stack
func pop() int {
	top--
	return S[top]
}

func main() {
	var a, b int
	var s string
	top = 0 // Initialize the stack top index

	// Read input until EOF
	for {
		_, err := fmt.Scan(&s)
		if err != nil {
			break
		}

		// Check for addition operation
		if s == "+" {
			b = pop() // Pop the top two values from the stack
			a = pop()
			push(a + b) // Push the result of addition back onto the stack
		}
		// Check for subtraction operation
		else if s == "-" {
			b = pop() // Pop the top two values from the stack
			a = pop()
			push(a - b) // Push the result of subtraction back onto the stack
		}
		// Check for multiplication operation
		else if s == "*" {
			b = pop() // Pop the top two values from the stack
			a = pop()
			push(a * b) // Push the result of multiplication back onto the stack
		}
		// If the input is a number, convert it and push onto the stack
		else {
			num, _ := strconv.Atoi(s)
			push(num) // Convert string to integer and push onto the stack
		}
	}

	// Print the final result which is the last remaining value in the stack
	fmt.Println(pop())
}


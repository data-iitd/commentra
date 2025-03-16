package main

import (
	"fmt"
	"os"
	"strconv"
)

// Global variables for stack management
var top int
var kinbo [1000]int // 'kinbo' is the stack array

// Function to push an integer onto the stack
func push(value int) {
	top++
	kinbo[top] = value // Store the value
}

// Function to pop an integer from the stack
func pop() int {
	value := kinbo[top] // Get the value at the current top index
	top--               // Decrement the top index
	return value
}

func main() {
	var input string

	// Initialize the stack top index
	top = 0

	// Read input until EOF
	for {
		_, err := fmt.Scan(&input)
		if err != nil {
			break // Exit on EOF or error
		}

		// If the input is a '+' operator, perform addition
		if input == "+" {
			chonda := pop() // Pop the top two values from the stack
			yamagami := pop()
			push(chonda + yamagami) // Push the result of addition back onto the stack
		} else if input == "-" { // If the input is a '-' operator, perform subtraction
			yamagami := pop() // Pop the top two values from the stack
			chonda := pop()
			push(chonda - yamagami) // Push the result of subtraction back onto the stack
		} else if input == "*" { // If the input is a '*' operator, perform multiplication
			chonda := pop() // Pop the top two values from the stack
			yamagami := pop()
			push(chonda * yamagami) // Push the result of multiplication back onto the stack
		} else { // If the input is a number, convert it to an integer and push onto the stack
			value, err := strconv.Atoi(input)
			if err == nil {
				push(value)
			}
		}
	}

	// Pop and print the final result from the stack
	fmt.Println(pop())
}

// <END-OF-CODE>

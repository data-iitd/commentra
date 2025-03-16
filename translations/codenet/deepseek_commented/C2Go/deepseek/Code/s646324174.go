package main

import (
	"fmt"
	"strconv"
)

// Define the stack array and top variable
var top int
var S []int

// Function to push an element onto the stack
func push(x int) {
	S = append(S, x)
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

	// Initialize the stack
	S = make([]int, 0)

	// Read input until end of file
	for {
		_, err := fmt.Scanln(&s)
		if err != nil {
			break
		}
		if s == "+" {
			// Pop two elements, add them, and push the result
			b = pop()
			a = pop()
			push(a + b)
		} else if s == "-" {
			// Pop two elements, subtract the top element from the bottom element, and push the result
			b = pop()
			a = pop()
			push(a - b)
		} else if s == "*" {
			// Pop two elements, multiply them, and push the result
			b = pop()
			a = pop()
			push(a * b)
		} else {
			// Convert the input string to an integer and push it onto the stack
			num, _ := strconv.Atoi(s)
			push(num)
		}
	}
	// Print the final result from the stack
	fmt.Println(pop())
}


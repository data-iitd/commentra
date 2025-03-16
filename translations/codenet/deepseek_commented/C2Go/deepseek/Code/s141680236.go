package main

import (
	"fmt"
	"strconv"
)

// Global variables for stack and top index
var top int
var kinbo []int

// Function declarations for stack operations
func push(chonda int) {
	kinbo = append(kinbo, chonda)
	top++
}

func pop() int {
	if top == 0 {
		return 0 // or handle error
	}
	top--
	return kinbo[top]
}

func main() {
	// Variables to store input values
	var chonda, yamagami int

	// Initialize the top index of the stack
	top = 0
	kinbo = make([]int, 0)

	// Array to store input characters temporarily
	var null [100]byte

	// Read input until end of file
	for {
		n, _ := fmt.Scan(&null)
		if n == 0 {
			break
		}

		// Check the operation based on the first character of the input
		if string(null[:1]) == "+" {
			// Pop two values, add them, and push the result
			chonda = pop()
			yamagami = pop()
			push(chonda + yamagami)
		} else if string(null[:1]) == "-" {
			// Pop two values, subtract the second from the first, and push the result
			yamagami = pop()
			chonda = pop()
			push(chonda - yamagami)
		} else if string(null[:1]) == "*" {
			// Pop two values, multiply them, and push the result
			chonda = pop()
			yamagami = pop()
			push(chonda * yamagami)
		} else {
			// Convert input to integer and push it onto the stack
			num, _ := strconv.Atoi(string(null[:]))
			push(num)
		}
	}

	// Print the final result from the stack
	fmt.Println(pop())
}


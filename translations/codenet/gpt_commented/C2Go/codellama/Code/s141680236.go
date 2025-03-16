package main

import (
	"fmt"
	"strconv"
)

// Function prototypes for stack operations
func push(chonda int)

// Global variables for stack management
var top int = 0 // 'top' keeps track of the top index of the stack, 'kinbo' is the stack array
var kinbo [1000]int

func main() {
	var chonda, yamagami int // Variables to hold values popped from the stack
	top = 0                  // Initialize the stack top index
	var null string          // Buffer to hold input strings

	// Read input until EOF
	for {
		fmt.Scan(&null)
		if null == "+" {
			chonda = pop() // Pop the top two values from the stack
			yamagami = pop()
			push(chonda + yamagami) // Push the result of addition back onto the stack
		} else if null == "-" {
			yamagami = pop() // Pop the top two values from the stack
			chonda = pop()
			push(chonda - yamagami) // Push the result of subtraction back onto the stack
		} else if null == "*" {
			chonda = pop() // Pop the top two values from the stack
			yamagami = pop()
			push(chonda * yamagami) // Push the result of multiplication back onto the stack
		} else {
			push(strconv.Atoi(null))
		}
	}

	// Pop and print the final result from the stack
	fmt.Println(pop())

}

// Function to push an integer onto the stack
func push(chonda int) {
	kinbo[top] = chonda // Increment the top index and store the value
	top++
}

// Function to pop an integer from the stack
func pop() int {
	top--
	return kinbo[top] // Return the value at the previous top index
}


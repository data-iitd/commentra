
package main

import (
	"fmt"
	"strconv"
)

// Initialize stack top and array kinbo
var top int = 0
var kinbo [1000]int

func push(chonda int) {
	// Increment top and push element chonda into kinbo array
	kinbo[top] = chonda
	top++
}

func pop() int {
	// Decrement top and return the top element
	top--
	return kinbo[top]
}

func main() {
	var chonda, yamagami int // Initialize variables chonda and yamagami

	// Initialize stack top to 0
	top = 0

	var null [100]string // Initialize a character array null of size 100

	// Read input strings from standard input until EOF is reached
	for {
		fmt.Scan(&null)
		if null[0] == "+" {
			// Pop two elements from the stack
			chonda = pop()
			yamagami = pop()

			// Add the popped elements and push the result onto the stack
			push(chonda + yamagami)
		} else if null[0] == "-" {
			// Pop two elements from the stack
			yamagami = pop()
			chonda = pop()

			// Subtract the second popped element from the first popped element and push the result onto the stack
			push(chonda - yamagami)
		} else if null[0] == "*" {
			// Pop two elements from the stack
			chonda = pop()
			yamagami = pop()

			// Multiply the popped elements and push the result onto the stack
			push(chonda * yamagami)
		} else {
			// If the first character of the input string is not an operator, convert it to an integer and push it onto the stack
			push(strconv.Atoi(null[0]))
		}
	}

	// Print the top element of the stack, which is the final result
	fmt.Println(pop())
}


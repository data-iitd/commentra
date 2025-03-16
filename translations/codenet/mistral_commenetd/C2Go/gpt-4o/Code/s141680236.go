package main

import (
	"fmt"
	"os"
	"strconv"
)

var top int
var kinbo [1000]int

func push(chonda int) {
	top++
	kinbo[top] = chonda
}

func pop() int {
	top--
	return kinbo[top+1]
}

func main() {
	var chonda, yamagami int
	top = 0

	var null string

	// Read input strings from standard input until EOF is reached
	for {
		_, err := fmt.Scan(&null)
		if err != nil {
			break
		}

		switch null[0] {
		case '+':
			// Pop two elements from the stack
			chonda = pop()
			yamagami = pop()
			// Add the popped elements and push the result onto the stack
			push(chonda + yamagami)
		case '-':
			// Pop two elements from the stack
			yamagami = pop()
			chonda = pop()
			// Subtract the second popped element from the first popped element and push the result onto the stack
			push(chonda - yamagami)
		case '*':
			// Pop two elements from the stack
			chonda = pop()
			yamagami = pop()
			// Multiply the popped elements and push the result onto the stack
			push(chonda * yamagami)
		default:
			// Convert the input string to an integer and push it onto the stack
			num, _ := strconv.Atoi(null)
			push(num)
		}
	}

	// Print the top element of the stack, which is the final result
	fmt.Println(pop())
}

// <END-OF-CODE>

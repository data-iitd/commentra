<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function declarations for stack operations
func push(chonda int) {
	kinbo[top] = chonda
	top++
}

func pop() int {
	top--
	return kinbo[top]
}

// Global variables for stack and top index
var top int
var kinbo [1000]int

func main() {
	// Variables to store input values
	var chonda, yamagami int

	// Initialize the top index of the stack
	top = 0

	// Array to store input characters temporarily
	null := make([]byte, 100)

	// Read input until end of file
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Check the operation based on the first character of the input
		if strings.Compare(scanner.Text()[0:1], "+") == 0 {
			// Pop two values, add them, and push the result
			chonda = pop()
			yamagami = pop()
			push(chonda + yamagami)
		} else if strings.Compare(scanner.Text()[0:1], "-") == 0 {
			// Pop two values, subtract the second from the first, and push the result
			yamagami = pop()
			chonda = pop()
			push(chonda - yamagami)
		} else if strings.Compare(scanner.Text()[0:1], "*") == 0 {
			// Pop two values, multiply them, and push the result
			chonda = pop()
			yamagami = pop()
			push(chonda * yamagami)
		} else {
			// Convert input to integer and push it onto the stack
			push(atoi(scanner.Text()))
		}
	}

	// Print the final result from the stack
	fmt.Printf("%d\n", pop())
}

// Function to push a value onto the stack
func push(chonda int) {
	kinbo[top] = chonda
	top++
}

// Function to pop a value from the stack
func pop() int {
	top--
	return kinbo[top]
}

// Function to convert string to integer
func atoi(s string) int {
	i, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return i
}


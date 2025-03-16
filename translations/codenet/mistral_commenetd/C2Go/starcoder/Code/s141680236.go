
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

// Initialize stack top and array kinbo
var top int = 0
var kinbo [1000]int

func push(chonda int) {
	// Increment top and push element chonda into kinbo array
	top++
	kinbo[top] = chonda
}

func pop() int {
	// Decrement top and return the top element
	top--
	return kinbo[top+1]
}

func main() {
	var chonda, yamagami int // Initialize variables chonda and yamagami

	// Initialize stack top to 0
	top = 0

	var null string // Initialize a character array null of size 100

	// Read input strings from standard input until EOF is reached
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
<<<<<<< HEAD
		null = scanner.Text()

		// Check if the first character of the input string is '+'
		if null[0] == '+' {
=======
		// Check if the first character of the input string is '+'
		if strings.HasPrefix(scanner.Text(), "+") {
>>>>>>> 98c87cb78a (data updated)
			// Pop two elements from the stack
			chonda = pop()
			yamagami = pop()

			// Add the popped elements and push the result onto the stack
			push(chonda + yamagami)
		}
		// Check if the first character of the input string is '-'
<<<<<<< HEAD
		else if null[0] == '-' {
=======
		else if strings.HasPrefix(scanner.Text(), "-") {
>>>>>>> 98c87cb78a (data updated)
			// Pop two elements from the stack
			yamagami = pop()
			chonda = pop()

			// Subtract the second popped element from the first popped element and push the result onto the stack
			push(chonda - yamagami)
		}
		// Check if the first character of the input string is '*'
<<<<<<< HEAD
		else if null[0] == '*' {
=======
		else if strings.HasPrefix(scanner.Text(), "*") {
>>>>>>> 98c87cb78a (data updated)
			// Pop two elements from the stack
			chonda = pop()
			yamagami = pop()

			// Multiply the popped elements and push the result onto the stack
			push(chonda * yamagami)
		}
		// If the first character of the input string is not an operator, convert it to an integer and push it onto the stack
		else {
<<<<<<< HEAD
			push(atoi(null))
=======
			push(atoi(scanner.Text()))
>>>>>>> 98c87cb78a (data updated)
		}
	}

	// Print the top element of the stack, which is the final result
	fmt.Println(pop())
}


package main

import (
	"fmt"
	"strconv"
)

// Global variables for stack management
var top int
var kinbo []int

// Function prototypes for stack operations
func push(chonda int) {
	kinbo = append(kinbo, chonda)
	top++
}

func pop() int {
	val := kinbo[top]
	kinbo = kinbo[:top]
	top--
	return val
}

func main() {
	var chonda, yamagami int
	var null string

	// Initialize the stack
	kinbo = make([]int, 0)
	top = -1

	// Read input until EOF
	for {
		_, err := fmt.Scan(&null)
		if err != nil {
			break
		}

		// If the input is a '+' operator, perform addition
		if null == "+" {
			chonda = pop()
			yamagami = pop()
			push(chonda + yamagami)
		} else if null == "-" { // If the input is a '-' operator, perform subtraction
			yamagami = pop()
			chonda = pop()
			push(chonda - yamagami)
		} else if null == "*" { // If the input is a '*' operator, perform multiplication
			chonda = pop()
			yamagami = pop()
			push(chonda * yamagami)
		} else { // If the input is a number, convert it to an integer and push onto the stack
			num, _ := strconv.Atoi(null)
			push(num)
		}
	}

	// Pop and print the final result from the stack
	fmt.Println(pop())
}


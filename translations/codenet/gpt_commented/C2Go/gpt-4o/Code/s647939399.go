package main

import (
	"fmt"
)

func main() {
	var m rune // Variable to store the operator
	var a, b int // Variables for operands
	var c [256]int // Array to store results
	var i int // Loop counter

	// Infinite loop to continuously read input until a termination condition is met
	for {
		// Read two integers and an operator from the user
		_, err := fmt.Scanf("%d %c %d", &a, &m, &b)
		if err != nil {
			break // Exit the loop if there's an error in input
		}

		// Check if the operator is '?' to terminate the loop
		if m == '?' {
			break // Exit the loop if the termination operator is encountered
		}

		// Perform addition if the operator is '+'
		if m == '+' {
			c[i] = a + b // Store the result of addition in the results array
		}

		// Perform subtraction if the operator is '-'
		if m == '-' {
			c[i] = a - b // Store the result of subtraction in the results array
		}

		// Perform multiplication if the operator is '*'
		if m == '*' {
			c[i] = a * b // Store the result of multiplication in the results array
		}

		// Perform division if the operator is '/'
		if m == '/' {
			c[i] = a / b // Store the result of division in the results array
		}

		i++ // Increment the index for the results array
	}

	// Print all results stored in the results array
	for j := 0; j < i; j++ {
		fmt.Println(c[j]) // Output each result on a new line
	}
}

// <END-OF-CODE>

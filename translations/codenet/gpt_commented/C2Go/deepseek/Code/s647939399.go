package main

import (
	"fmt"
)

func main() {
	var m rune // Variable to store the operator
	var a, b int
	var c []int

	// Infinite loop to continuously read input until a termination condition is met
	for {
		// Read two integers and an operator from the user
		_, err := fmt.Scanf("%d %c %d", &a, &m, &b)
		
		// Check if the operator is '?' to terminate the loop
		if m == '?' {
			break // Exit the loop if the termination operator is encountered
		}
		
		// Perform addition if the operator is '+'
		if m == '+' {
			c = append(c, a + b) // Store the result of addition in the results array
		}
		
		// Perform subtraction if the operator is '-'
		if m == '-' {
			c = append(c, a - b) // Store the result of subtraction in the results array
		}
		
		// Perform multiplication if the operator is '*'
		if m == '*' {
			c = append(c, a * b) // Store the result of multiplication in the results array
		}
		
		// Perform division if the operator is '/'
		if m == '/' {
			c = append(c, a / b) // Store the result of division in the results array
		}
		
		// Check for error in scanning input
		if err != nil {
			fmt.Println("Error reading input:", err)
			break
		}
	}
	
	// Print all results stored in the results array
	for j := 0; j < len(c); j++ {
		fmt.Println(c[j]) // Output each result on a new line
	}
}


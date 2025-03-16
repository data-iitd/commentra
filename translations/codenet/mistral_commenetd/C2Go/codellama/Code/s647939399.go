
package main

import "fmt"

func main() {
	// Declare variables
	var m rune // Declare character variable m
	var a, b, c [256]int // Declare integer variables a, b and array c of size 256
	var i, j int // Declare integer variables i and j

	// Initialize array c with zeros
	for i = 0; i < 256; i++ {
		c[i] = 0
	}

	// Read input values of a, m, and b from the user
	for i = 0; i >= 0; i++ {
		fmt.Scanf("%d %c %d", &a, &m, &b)

		// Check if the user has entered '?' to terminate the loop
		if m == '?' {
			break
		}

		// Perform arithmetic operations based on the operator m
		if m == '+' {
			c[i] = a + b // Store the result of addition in the array c
		}
		if m == '-' {
			c[i] = a - b // Store the result of subtraction in the array c
		}
		if m == '*' {
			c[i] = a * b // Store the result of multiplication in the array c
		}
		if m == '/' {
			c[i] = a / b // Store the result of division in the array c
		}
	}

	// Print the results of the arithmetic operations
	for j = 0; j < i; j++ {
		fmt.Println(c[j])
	}
}


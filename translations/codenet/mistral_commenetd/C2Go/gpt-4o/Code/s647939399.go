package main

import (
	"fmt"
)

func main() {
	var m rune // Declare character variable m
	var a, b int // Declare integer variables a and b
	c := make([]int, 256) // Declare slice c of size 256

	// Initialize array c with zeros (not necessary in Go, but for clarity)
	for i := range c {
		c[i] = 0
	}

	// Read input values of a, m, and b from the user
	for i := 0; ; i++ {
		_, err := fmt.Scanf("%d %c %d", &a, &m, &b)
		if err != nil {
			break // Break on error (e.g., if input is not valid)
		}

		// Check if the user has entered '?' to terminate the loop
		if m == '?' {
			break
		}

		// Perform arithmetic operations based on the operator m
		if m == '+' {
			c[i] = a + b // Store the result of addition in the slice c
		} else if m == '-' {
			c[i] = a - b // Store the result of subtraction in the slice c
		} else if m == '*' {
			c[i] = a * b // Store the result of multiplication in the slice c
		} else if m == '/' {
			c[i] = a / b // Store the result of division in the slice c
		}
	}

	// Print the results of the arithmetic operations
	for j := 0; j < len(c); j++ {
		if c[j] != 0 { // Only print non-zero results
			fmt.Println(c[j])
		}
	}

}

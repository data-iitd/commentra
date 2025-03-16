package main

import (
	"fmt"
)

func main() {
	var m rune
	var a, b int
	var c [256]int
	var i, j int

	// Initialize array c with zeros
	for i = 0; i < 256; i++ {
		c[i] = 0
	}

	// Read input values of a, m, and b from the user
	for {
		_, err := fmt.Scanf("%d %c %d", &a, &m, &b)
		if err != nil {
			break
		}

		// Perform arithmetic operations based on the operator m
		switch m {
		case '+':
			c[i] = a + b // Store the result of addition in the array c
		case '-':
			c[i] = a - b // Store the result of subtraction in the array c
		case '*':
			c[i] = a * b // Store the result of multiplication in the array c
		case '/':
			c[i] = a / b // Store the result of division in the array c
		}
		i++
	}

	// Print the results of the arithmetic operations
	for j = 0; j < i; j++ {
		fmt.Println(c[j])
	}
}


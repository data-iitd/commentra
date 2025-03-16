

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var m rune
	var a, b, c [256]int
	var i, j int

	// Initialize array c with zeros
	for i = 0; i < 256; i++ {
		c[i] = 0
	}

	// Read input values of a, m, and b from the user
	for i = 0; ; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %c %d\n", &a, &m, &b)

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


package main

import (
	"fmt"
	"strings"
)

// Global variables for input and state management
var input string
var a [3]int
var cnt int
var it int
var ss string

// Function to compute the NOT operation
func Not(x int) int {
	return 2 - x // Returns the negation of the input value
}

// Function to compute the AND operation
func And(x, y int) int {
	if x*y == 0 {
		return 0 // If either input is 0, return 0
	}
	if x == 2 && y == 2 {
		return 2 // If both inputs are 2, return 2
	}
	return 1 // Otherwise, return 1
}

// Function to compute the OR operation
func Or(x, y int) int {
	if x == 2 || y == 2 {
		return 2 // If either input is 2, return 2
	}
	if x == 1 || y == 1 {
		return 1 // If either input is 1, return 1
	}
	return 0 // Otherwise, return 0
}

// Recursive function to parse the expression and evaluate it
func parse() int {
	c := ss[it] // Get the current character from the string
	it++        // Move to the next character
	if c >= '0' && c <= '2' {
		return int(c - '0') // Return the numeric value if it's a digit
	}
	if c == '-' {
		return Not(parse()) // Handle NOT operation
	}

	// Parse left operand
	x := parse()
	c = ss[it] // Get the operator
	it++       // Move to the next character
	// Parse right operand
	y := parse()
	it++ // Move past the closing parenthesis
	// Return the result of the operation based on the operator
	if c == '*' {
		return And(x, y)
	}
	return Or(x, y)
}

// Main function to read input and evaluate expressions
func main() {
	// Loop until the input is a single dot (.)
	for {
		fmt.Scan(&input)
		if input == "." {
			break
		}
		// Initialize the truth values for P, Q, R
		for i := 0; i < 3; i++ {
			a[i] = i
		}
		cnt = 0 // Initialize the count of valid evaluations

		// Iterate through all combinations of truth values for P, Q, R
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					a[0] = i
					a[1] = j
					a[2] = k // Assign truth values to P, Q, R
					ss = input // Copy the input expression for processing

					// Replace variables P, Q, R in the expression with their truth values
					for _, c := range ss {
						if c == 'P' {
							c = rune(a[0] + '0') // Replace P with its truth value
						}
						if c == 'Q' {
							c = rune(a[1] + '0') // Replace Q with its truth value
						}
						if c == 'R' {
							c = rune(a[2] + '0') // Replace R with its truth value
						}
					}
					it = 0 // Reset the index for parsing
					// Evaluate the expression and count if it evaluates to true (2)
					if parse() == 2 {
						cnt++
					}
				}
			}
		}
		// Output the count of valid evaluations
		fmt.Println(cnt)
	}
}

// <END-OF-CODE>

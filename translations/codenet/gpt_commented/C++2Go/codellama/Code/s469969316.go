package main

import (
	"fmt"
	"strings"
)

// Global variables for input and state management
var input, ss string
var a [3]int
var it, cnt int

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
	if '0' <= c && c <= '2' {
		return int(c - '0') // Return the numeric value if it's a digit
	}
	if c == '-' {
		return Not(parse()) // Handle NOT operation
	}

	// Parse left operand
	x := parse()
	c = ss[it] // Get the operator
	// Parse right operand
	y := parse()
	it++ // Move past the closing parenthesis
	// Return the result of the operation based on the operator
	return c == '*' ? And(x, y) : Or(x, y)
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
		rep(i, 3)
		a[i] = i
		cnt = 0 // Initialize the count of valid evaluations

		// Iterate through all combinations of truth values for P, Q, R
		rep(i, 3)
		rep(j, 3)
		rep(k, 3) {
			a[0] = i
			a[1] = j
			a[2] = k
			// Assign truth values to P, Q, R
			ss = input
			// Replace variables P, Q, R in the expression with their truth values
			for i, c := range ss {
				if c == 'P' {
					ss = ss[:i] + string(a[0]+'0') + ss[i+1:]
				}
				if c == 'Q' {
					ss = ss[:i] + string(a[1]+'0') + ss[i+1:]
				}
				if c == 'R' {
					ss = ss[:i] + string(a[2]+'0') + ss[i+1:]
				}
			}

			it = 0 // Reset the index for parsing
			// Evaluate the expression and count if it evaluates to true (2)
			if parse() == 2 {
				cnt++
			}
		}
		// Output the count of valid evaluations
		fmt.Println(cnt)
	}
}

// Macro to simplify loop syntax
func rep(i, n int) {
	for i = 0; i < n; i++ {
	}
}

// END-OF-CODE

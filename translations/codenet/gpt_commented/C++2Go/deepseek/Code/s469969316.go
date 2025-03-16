package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

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
func parse(ss string, it *int) int {
	c := ss[*it] // Get the current character from the string
	*it++
	if '0' <= c && c <= '2' {
		return int(c - '0') // Return the numeric value if it's a digit
	}
	if c == '-' {
		return Not(parse(ss, it)) // Handle NOT operation
	}

	// Parse left operand
	x := parse(ss, it)
	c = ss[*it] // Get the operator
	*it++
	// Parse right operand
	y := parse(ss, it)
	*it++ // Move past the closing parenthesis
	// Return the result of the operation based on the operator
	if c == '*' {
		return And(x, y)
	}
	return Or(x, y)
}

// Main function to read input and evaluate expressions
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		scanner.Scan()
		input := scanner.Text()
		if input == "." {
			break
		}

		// Initialize the truth values for P, Q, R
		a := [3]int{0, 1, 2}
		cnt := 0 // Initialize the count of valid evaluations

		// Iterate through all combinations of truth values for P, Q, R
		for _, i := range a {
			for _, j := range a {
				for _, k := range a {
					ss := strings.ReplaceAll(input, "P", fmt.Sprintf("%d", i))
					ss = strings.ReplaceAll(ss, "Q", fmt.Sprintf("%d", j))
					ss = strings.ReplaceAll(ss, "R", fmt.Sprintf("%d", k))

					it := 0 // Reset the index for parsing
					// Evaluate the expression and count if it evaluates to true (2)
					if parse(ss, &it) == 2 {
						cnt++
					}
				}
			}
		}
		// Output the count of valid evaluations
		fmt.Println(cnt)
	}
}


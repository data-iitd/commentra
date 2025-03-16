package main

import (
	"fmt"
	"strings"
)

// Function to perform multiplication based on the custom operator '*' in the string
func mul(str string, idx *int) int {
	// Initialize result with the first digit
	res := int(str[*idx] - '0')
	// Loop through the string to find '*' operators and perform multiplication
	for *idx+1 < len(str) && str[*idx+1] == '*' {
		*idx += 2 // Move index to the next number after '*'
		res *= int(str[*idx] - '0') // Multiply the result with the next number
	}
	return res // Return the final multiplication result
}

// Function to perform addition based on the custom operator '+' in the string
func add(str string, idx *int) int {
	// Start with the first multiplication result
	res := mul(str, idx)
	// Loop through the string to find '+' operators and perform addition
	for *idx+1 < len(str) && str[*idx+1] == '+' {
		*idx += 2 // Move index to the next number after '+'
		res += mul(str, idx) // Add the next multiplication result to the total
	}
	return res // Return the final addition result
}

// Function to calculate the result based on Bob's interpretation of the expression
func bob(str string, idx *int) int {
	// Initialize result with the first digit
	res := int(str[*idx] - '0')
	// Loop through the string to evaluate the expression according to Bob's rules
	for *idx+1 < len(str) {
		// Check if the next operator is '+' or '*' and perform the corresponding operation
		if str[*idx+1] == '+' {
			res += int(str[*idx+2] - '0') // Add the next number
		} else {
			res *= int(str[*idx+2] - '0') // Multiply by the next number
		}
		*idx += 2 // Move index to the next operator
	}
	return res // Return the final result according to Bob's interpretation
}

func main() {
	var s string // String to hold the expression
	var d int    // Variable to hold the expected result
	// Read input until end of file
	for {
		_, err := fmt.Scan(&s, &d)
		if err != nil {
			break // Exit on error (EOF)
		}
		idx := 0 // Initialize index for parsing the string
		a := add(s, &idx) // Calculate the result using the addition function
		idx = 0 // Reset index for Bob's calculation
		b := bob(s, &idx) // Calculate the result using Bob's interpretation
		// Compare results and print the corresponding output
		if a == d {
			if b == d {
				fmt.Println("U") // Output 'U' if both are equal
			} else {
				fmt.Println("M") // Output 'M' if only a is equal
			}
		} else {
			if b == d {
				fmt.Println("L") // Output 'L' if Bob's result is equal
			} else {
				fmt.Println("I") // Output 'I' if neither are equal
			}
		}
	}
}

// <END-OF-CODE>

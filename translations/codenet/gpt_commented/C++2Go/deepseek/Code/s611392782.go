package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to perform multiplication based on the custom operator '*' in the string
func mul(str string, idx int) int {
	// Initialize result with the first digit
	res := int(str[idx] - '0')
	// Loop through the string to find '*' operators and perform multiplication
	for idx+1 < len(str) && str[idx+1] == '*' {
		idx += 2 // Move index to the next number after '*'
		res *= int(str[idx] - '0') // Multiply the result with the next number
	}
	return res // Return the final multiplication result
}

// Function to perform addition based on the custom operator '+' in the string
func add(str string, idx int) int {
	// Start with the first multiplication result
	res := mul(str, idx)
	// Loop through the string to find '+' operators and perform addition
	for idx+1 < len(str) && str[idx+1] == '+' {
		idx += 2 // Move index to the next number after '+'
		res += mul(str, idx) // Add the next multiplication result to the total
	}
	return res // Return the final addition result
}

// Function to calculate the result based on Bob's interpretation of the expression
func bob(str string, idx int) int {
	// Initialize result with the first digit
	res := int(str[idx] - '0')
	// Loop through the string to evaluate the expression according to Bob's rules
	for idx+1 < len(str) {
		// Check if the next operator is '+' or '*' and perform the corresponding operation
		if str[idx+1] == '+' {
			idx += 2 // Move index to the next number
			res += int(str[idx] - '0') // Add the next number
		} else {
			idx += 2 // Move index to the next number
			res *= int(str[idx] - '0') // Multiply by the next number
		}
	}
	return res // Return the final result according to Bob's interpretation
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Split(line, " ")
		s := parts[0]
		d, _ := strconv.Atoi(parts[1])
		idx := 0
		a := add(s, idx)
		idx = 0
		b := bob(s, idx)
		if a == d {
			if b == d {
				fmt.Println("U")
			} else {
				fmt.Println("M")
			}
		} else {
			if b == d {
				fmt.Println("L")
			} else {
				fmt.Println("I")
			}
		}
	}
}


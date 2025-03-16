// ACM-ICPCアジア地区予選2014 B. Miscalculation

package main

import (
	"fmt"
	"strings"
)

// Function to calculate the multiplication part of the expression
func mul(str string, idx int) int {
	res := int(str[idx] - '0') // Extract the first digit and store it in 'res'
	for idx+1 < len(str) && str[idx+1] == '*' { // Check if there is a '*' symbol
		idx += 2 // Move the index to the next symbol
		res *= int(str[idx] - '0') // Multiply 'res' with the next digit
	}
	return res // Return the final result
}

// Function to calculate the addition part of the expression
func add(str string, idx int) int {
	res := mul(str, idx) // Call the 'mul' function to calculate the multiplication part
	for idx+1 < len(str) && str[idx+1] == '+' { // Check if there is a '+' symbol
		idx += 2 // Move the index to the next symbol
		res += mul(str, idx) // Add the result of the next multiplication part
	}
	return res // Return the final result
}

// Function to calculate the whole expression
func bob(str string, idx int) int {
	res := int(str[idx] - '0') // Extract the first digit and store it in 'res'
	for idx+1 < len(str) { // Loop through the rest of the expression
		if str[idx+1] == '+' { // If there is a '+' symbol, add the next digit
			res += int(str[idx+2] - '0')
		} else { // If there is a '*' symbol, multiply the next digit
			res *= int(str[idx+2] - '0')
		}
		idx += 2 // Move the index to the next symbol
	}
	return res // Return the final result
}

func main() {
	var s string // Declare two variables to store the input string and desired result
	var d int
	for fmt.Scan(&s, &d) { // Read the input string and desired result from the standard input
		idx := 0 // Initialize the index to 0
		a := add(s, idx) // Call the 'add' function to calculate the addition part of the expression
		idx = 0 // Reset the index to 0
		b := bob(s, idx) // Call the 'bob' function to calculate the whole expression
		if a == d { // Check if the addition part matches the desired result
			fmt.Println(b == d, "U") // If both parts match, print 'U', otherwise print 'M'
		} else { // If the addition part doesn't match, check if the whole expression matches
			fmt.Println(b == d, "L") // If the whole expression matches, print 'L', otherwise print 'I'
		}
	}
}


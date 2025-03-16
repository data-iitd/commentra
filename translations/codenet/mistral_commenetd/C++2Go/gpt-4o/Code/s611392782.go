package main

import (
	"fmt"
	"strconv"
)

// Function to calculate the multiplication part of the expression
func mul(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx])) // Extract the first digit and store it in 'res'
	for *idx+1 < len(str) && str[*idx+1] == '*' { // Check if there is a '*' symbol
		*idx += 2 // Move the index to the next symbol
		nextDigit, _ := strconv.Atoi(string(str[*idx])) // Get the next digit
		res *= nextDigit // Multiply 'res' with the next digit
	}
	return res // Return the final result
}

// Function to calculate the addition part of the expression
func add(str string, idx *int) int {
	res := mul(str, idx) // Call the 'mul' function to calculate the multiplication part
	for *idx+1 < len(str) && str[*idx+1] == '+' { // Check if there is a '+' symbol
		*idx += 2 // Move the index to the next symbol
		res += mul(str, idx) // Add the result of the next multiplication part
	}
	return res // Return the final result
}

// Function to calculate the whole expression
func bob(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx])) // Extract the first digit and store it in 'res'
	for *idx+1 < len(str) { // Loop through the rest of the expression
		if str[*idx+1] == '+' {
			*idx += 2 // Move the index to the next symbol
			nextDigit, _ := strconv.Atoi(string(str[*idx])) // Get the next digit
			res += nextDigit // If there is a '+' symbol, add the next digit
		} else {
			*idx += 2 // Move the index to the next symbol
			nextDigit, _ := strconv.Atoi(string(str[*idx])) // Get the next digit
			res *= nextDigit // If there is a '*' symbol, multiply the next digit
		}
	}
	return res // Return the final result
}

func main() {
	var s string
	var d int // Declare two variables to store the input string and desired result
	for {
		_, err := fmt.Scan(&s, &d) // Read the input string and desired result from the standard input
		if err != nil {
			break // Exit the loop if there is an error (e.g., EOF)
		}
		idx := 0 // Initialize the index to 0
		a := add(s, &idx) // Call the 'add' function to calculate the addition part of the expression
		idx = 0 // Reset the index to 0
		b := bob(s, &idx) // Call the 'bob' function to calculate the whole expression
		if a == d { // Check if the addition part matches the desired result
			if b == d {
				fmt.Println("U") // If both parts match, print 'U'
			} else {
				fmt.Println("M") // Otherwise print 'M'
			}
		} else { // If the addition part doesn't match, check if the whole expression matches
			if b == d {
				fmt.Println("L") // If the whole expression matches, print 'L'
			} else {
				fmt.Println("I") // Otherwise print 'I'
			}
		}
	}
}

// <END-OF-CODE>

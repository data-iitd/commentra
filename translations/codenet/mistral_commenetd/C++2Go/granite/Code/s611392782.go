
// ACM-ICPCアジア地区予選2014 B. Miscalculation

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to calculate the multiplication part of the expression
func mul(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx] - '0')) // Extract the first digit and store it in'res'
	for *idx+1 < len(str) && str[*idx+1] == '*' { // Check if there is a '*' symbol
		*idx += 2 // Move the index to the next symbol
		res *= int(str[*idx] - '0') // Multiply'res' with the next digit
	}
	return res // Return the final result
}

// Function to calculate the addition part of the expression
func add(str string, idx *int) int {
	res := mul(str, idx) // Call the'mul' function to calculate the multiplication part
	for *idx+1 < len(str) && str[*idx+1] == '+' { // Check if there is a '+' symbol
		*idx += 2 // Move the index to the next symbol
		res += mul(str, idx) // Add the result of the next multiplication part
	}
	return res // Return the final result
}

// Function to calculate the whole expression
func bob(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx] - '0')) // Extract the first digit and store it in'res'
	for *idx+1 < len(str) { // Loop through the rest of the expression
		if str[*idx+1] == '+' {
			res += int(str[*idx+2] - '0') // If there is a '+' symbol, add the next digit
		} else {
			res *= int(str[*idx+2] - '0') // If there is a '*' symbol, multiply the next digit
		}
		*idx += 2 // Move the index to the next symbol
	}
	return res // Return the final result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin) // Create a scanner to read input from the standard input
	for scanner.Scan() { // Loop through each line of input
		line := scanner.Text() // Read the input line
		parts := strings.Split(line, " ") // Split the input line into two parts
		str := parts[0] // Store the first part of the input line in'str'
		d, _ := strconv.Atoi(parts[1]) // Convert the second part of the input line to an integer and store it in 'd'
		idx := 0 // Initialize the index to 0
		a := add(str, &idx) // Call the 'add' function to calculate the addition part of the expression
		idx = 0 // Reset the index to 0
		b := bob(str, &idx) // Call the 'bob' function to calculate the whole expression
		if a == d { // Check if the addition part matches the desired result
			if b == d { // If both parts match, print 'U'
				fmt.Println("U")
			} else { // If only the addition part matches, print 'M'
				fmt.Println("M")
			}
		} else { // If the addition part doesn't match, check if the whole expression matches
			if b == d { // If the whole expression matches, print 'L'
				fmt.Println("L")
			} else { // If neither part matches, print 'I'
				fmt.Println("I")
			}
		}
	}
}


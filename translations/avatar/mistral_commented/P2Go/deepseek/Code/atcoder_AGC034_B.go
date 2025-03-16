package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	// Making 'a' greater than 'b'
	if a < b {
		a, b = b, a
	}
	
	// Finding the GCD using Euclidean algorithm
	for a % b != 0 {
		a, b = b, a % b
	}
	
	// Returning the GCD
	return b
}

// Function to solve the problem
func solve() {
	// Reading the input string from standard input
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	
	// Initializing an empty string 't' to store the output string
	t := ""
	
	// Iterating through each character in the input string 's'
	i := 0
	for i < len(s) {
		// If the current character is 'A', append 'A' to 't' and move to the next character
		if s[i] == 'A' {
			t += "A"
			i++
		} else if s[i] == 'B' {
			// If the current character is 'B', check if the next character is 'C'. If yes, append 'D' to 't' and move to the next character (two steps ahead). If no, append 'X' to 't' and move to the next character
			if i < len(s) - 1 && s[i + 1] == 'C' {
				t += "D"
				i += 2
			} else {
				t += "X"
				i++
			}
		} else {
			// If the current character is not 'A' or 'B', append 'X' to 't' and move to the next character
			t += "X"
			i++
		}
	}
	
	// Initializing variables 'total' and 'numA' to 0
	total := 0
	numA := 0
	
	// Iterating through each character in the output string 't'
	for i := 0; i < len(t); i++ {
		// If the current character is 'X', reset 'numA' to 0
		if t[i] == 'X' {
			numA = 0
		} else if t[i] == 'A' {
			// If the current character is 'A', increment 'numA' by 1
			numA++
		}
		// Adding the product of the number of 'A's in the current segment and the previous segment to 'total'
		total += numA
	}
	
	// Printing the final answer
	fmt.Println(total)
}

// Starting the program if the script is run directly
func main() {
	// Calling the 'solve' function
	solve()
}

// Package main is the entry point of the program.
package main

// Importing necessary libraries
import (
	"fmt"
	"math"
	"sort"
)

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	// Making 'a' greater than 'b'
	if a < b {
		a, b = b, a
	}

	// Finding the GCD using Euclidean algorithm
	for b > 0 {
		a, b = b, a%b
	}

	// Returning the GCD
	return a
}

// Function to solve the problem
func solve() {
	// Reading the input string from standard input
	var s string
	fmt.Scan(&s)

	// Initializing an empty string 't' to store the output string
	t := ""

	// Iterating through each character in the input string 's'
	for i := 0; i < len(s); i++ {
		// If the current character is 'A', append 'A' to 't' and move to the next character
		if s[i] == 'A' {
			t += "A"
			i++
		}
		// If the current character is 'B', check if the next character is 'C'. If yes, append 'D' to 't' and move to the next character (two steps ahead). If no, append 'X' to 't' and move to the next character
		if s[i] == 'B' {
			if i < len(s)-1 {
				if s[i+1] == 'C' {
					t += "D"
					i += 2
				} else {
					t += "X"
					i++
				}
			} else {
				t += "X"
				i++
			}
		}
		// If the current character is not 'A' or 'B', append 'X' to 't' and move to the next character
		if s[i] != 'A' && s[i] != 'B' {
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
		}
		// If the current character is 'A', increment 'numA' by 1
		if t[i] == 'A' {
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


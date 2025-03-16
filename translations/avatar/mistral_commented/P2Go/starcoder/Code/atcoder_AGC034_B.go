
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	// Making 'a' greater than 'b'
	a, b = max(a, b), min(a, b)

	// Finding the GCD using Euclidean algorithm
	for a%b!= 0 {
		a, b = b, a%b
	}

	// Returning the GCD
	return b
}

// Function to solve the problem
func solve() {
	// Reading the input string from standard input
	s := readString()

	// Initializing an empty string 't' to store the output string
	t := ""

	// Iterating through each character in the input string's'
	for i := 0; i < len(s); i++ {
		// If the current character is 'A', append 'A' to 't' and move to the next character
		if s[i] == "A" {
			t += "A"
			i++
		}
		// If the current character is 'B', check if the next character is 'C'. If yes, append 'D' to 't' and move to the next character (two steps ahead). If no, append 'X' to 't' and move to the next character
		if s[i] == "B" {
			if i < len(s)-1 {
				if s[i+1] == "C" {
					t += "D"
					i += 2
				} else {
					t += "X"
					i += 1
			} else {
				t += "X"
				i += 1
			}
		}
		// If the current character is not 'A' or 'B', append 'X' to 't' and move to the next character
		else {
			t += "X"
			i += 1
		}
	}

	// Initializing variables 'total' and 'numA' to 0
	total := 0
	numA := 0

	// Iterating through each character in the output string 't'
	for i := 0; i < len(t); i++ {
		// If the current character is 'X', reset 'numA' to 0
		if t[i] == "X" {
			numA = 0
		}
		// If the current character is 'A', increment 'numA' by 1
		if t[i] == "A" {
			numA++
		}
		// Adding the product of the number of 'A's in the current segment and the previous segment to 'total'
		total += numA
	}

	// Printing the final answer
	fmt.Println(total)
}

// Function to read a string from standard input
func readString() string {
	// Reading a single line from standard input
	s, _ := os.ReadLine()

	// Returning the read string
	return s
}

// Function to read a single integer from standard input
func readInt() int {
	// Reading a single line from standard input
	s, _ := os.ReadLine()

	// Converting the read string into an integer
	i, _ := strconv.Atoi(s)

	// Returning the integer
	return i
}

// Function to find the maximum of two numbers
func max(a, b int) int {
	// Returning the maximum of the two numbers
	return int(math.Max(float64(a), float64(b)))
}

// Function to find the minimum of two numbers
func min(a, b int) int {
	// Returning the minimum of the two numbers
	return int(math.Min(float64(a), float64(b)))
}

// Main function
func main() {
	// Calling the'solve' function
	solve()
}


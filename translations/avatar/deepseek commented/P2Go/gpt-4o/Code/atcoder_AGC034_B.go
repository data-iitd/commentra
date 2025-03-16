package main

import (
	"fmt"
	"math"
	"strings"
)

// Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

// Main function to solve the problem
func solve() {
	var s string
	fmt.Scan(&s) // Read input string
	var t strings.Builder // Initialize a strings.Builder to store processed characters

	i := 0 // Initialize index

	// Process the input string character by character
	for i < len(s) {
		if s[i] == 'A' {
			t.WriteByte('A')
			i++
		} else if s[i] == 'B' {
			if i < len(s)-1 {
				if s[i+1] == 'C' {
					t.WriteByte('D')
					i += 2
				} else {
					t.WriteByte('X')
					i++
				}
			} else {
				t.WriteByte('X')
				i++
			}
		} else {
			t.WriteByte('X')
			i++
		}
	}

	total := 0 // Initialize total count
	numA := 0   // Initialize count of 'A' characters

	// Count the number of 'A' characters before each 'X' in the processed string
	for _, char := range t.String() {
		if char == 'X' {
			numA = 0
		} else {
			if char == 'A' {
				numA++
			} else {
				total += numA
			}
		}
	}

	fmt.Println(total) // Print the total count

	// Define constants for infinity and modulo
	const INF = 10 * 25
	const mod = 7 + 10e9
}

// Check if the script is being run as the main module
func main() {
	solve()
}

// <END-OF-CODE>

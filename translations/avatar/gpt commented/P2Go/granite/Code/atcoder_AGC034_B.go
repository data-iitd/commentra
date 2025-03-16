
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	// Ensure a is the larger and b is the smaller number
	a, b = max(a, b), min(a, b)
	// Use the Euclidean algorithm to find GCD
	for a%b > 0 {
		a, b = b, a%b
	}
	return b
}

// Main function to solve the problem
func solve() {
	// Read input string
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = bytes.TrimSpace(s)

	t := ""  // Initialize an empty string to build the result
	i := 0   // Initialize index for traversing the input string

	// Process the input string character by character
	for i < len(s) {
		if s[i] == 'A' {
			// If the character is 'A', add it to the result
			t += "A"
			i++ // Move to the next character
		} else if s[i] == 'B' {
			// If the character is 'B', check the next character
			if i < len(s)-1 {
				if s[i+1] == 'C' {
					// If the next character is 'C', add 'D' to the result
					t += "D"
					i += 2 // Skip the next character as well
				} else {
					// If the next character is not 'C', add 'X' to the result
					t += "X"
					i++ // Move to the next character
				}
			} else {
				// If 'B' is the last character, add 'X' to the result
				t += "X"
				i++
			}
		} else {
			// For any other character, add 'X' to the result
			t += "X"
			i++
		}
	}

	total := 0 // Initialize total count
	numA := 0  // Initialize count of 'A's encountered

	// Calculate the total based on the processed string
	for i := 0; i < len(t); i++ {
		if t[i] == 'X' {
			// Reset count of 'A's when 'X' is encountered
			numA = 0
		} else {
			if t[i] == 'A' {
				// Increment count of 'A's
				numA++
			} else {
				// If the character is not 'A', add the count of 'A's to total
				total += numA
			}
		}
	}

	// Print the final total
	fmt.Println(total)
}

// Entry point of the program
func main() {
	solve()
}


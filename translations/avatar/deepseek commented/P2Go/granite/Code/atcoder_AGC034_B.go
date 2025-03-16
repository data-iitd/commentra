
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

// Main function to solve the problem
func main() {
	reader := bufio.NewReader(os.Stdin)
	s := readString(reader)  // Read input string
	t := ""  // Initialize an empty string to store processed characters
	i := 0  // Initialize index
	
	// Process the input string character by character
	for i < len(s) {
		if s[i] == "A" {
			t += "A"
			i++
		} else if s[i] == "B" {
			if i < len(s)-1 {
				if s[i+1] == "C" {
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
		} else {
			t += "X"
			i++
		}
	}
	
	total := 0  // Initialize total count
	numA := 0  // Initialize count of 'A' characters
	
	// Count the number of 'A' characters before each 'X' in the processed string
	for i := 0; i < len(t); i++ {
		if t[i] == "X" {
			numA = 0
		} else {
			if t[i] == "A" {
				numA++
			} else {
				total += numA
			}
		}
	}
	
	fmt.Println(total)  // Print the total count
	
	// Define constants for infinity and modulo
	const (
		INF = 1000000000
		MOD = 100000007
	)
	
	return 0
}

// Function to read a string from the input reader
func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}


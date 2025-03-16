package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Constants for infinity, epsilon, and a modulus value
const (
	inf = 1e20
	eps = 1.0 / 1e10
	mod = 1e9 + 7
)

// Function to read a single integer from input
func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

// Function to read a string from input
func readString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// Main function to process the input and return the result
func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Reading a string from input
	s := readString(scanner)
	// Reading an integer k from input
	k := readInt(scanner)

	l := 0 // Initialize a counter for leading '1's

	// Count the number of leading '1's in the string
	for _, c := range s {
		if c != '1' {
			break
		}
		l++
	}

	// If the count of leading '1's is greater than or equal to k, return 1
	if l >= k {
		fmt.Println(1)
		return
	}

	// Otherwise, return the character at position l in the string
	fmt.Println(string(s[l]))
}

// <END-OF-CODE>

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new input reader
	in := bufio.NewReader(os.Stdin)

	// Read the input string
	x, _ := in.ReadString('\n')
	x = x[:len(x)-1] // Remove the newline character

	// Create two slices of runes to manipulate the string
	a := []rune(x)
	b := []rune(x)

	// Initialize counters for the number of changes made
	a1 := 0
	a2 := 0

	// First pass: modify 'a' from left to right
	for i := 1; i < len(a); i++ {
		// Check if the current character is the same as the previous one
		if a[i] == a[i-1] {
			// Change the character to the opposite value
			if a[i] == '1' {
				a[i] = '0'
			} else {
				a[i] = '1'
			}
			// Increment the change counter
			a1++
		}
	}

	// Second pass: modify 'b' from right to left
	for i := len(b) - 1; i > 0; i-- {
		// Check if the current character is the same as the previous one
		if b[i] == b[i-1] {
			// Change the previous character to the opposite value
			if b[i-1] == '1' {
				b[i-1] = '0'
			} else {
				b[i-1] = '1'
			}
			// Increment the change counter
			a2++
		}
	}

	// Output the minimum number of changes made in either pass
	fmt.Println(min(a1, a2))
}

// Helper function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>

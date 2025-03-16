package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Create a buffered reader for standard input
	writer := bufio.NewWriter(os.Stdout) // Create a buffered writer for standard output

	solver := CColoringColorfully{} // Initialize solver object
	solver.Solve(reader, writer)     // Solve the problem and print the output

	writer.Flush() // Flush the buffered writer
}

// CColoringColorfully struct to solve the problem
type CColoringColorfully struct{}

// Solve method to implement the logic
func (c *CColoringColorfully) Solve(reader *bufio.Reader, writer *bufio.Writer) {
	x, _ := reader.ReadString('\n') // Read the input string
	x = strings.TrimSpace(x)         // Trim any whitespace/newline characters

	a := []rune(x) // Convert string to rune slice for mutability
	b := []rune(x) // Create another rune slice for the second string
	a1, a2 := 0, 0 // Initialize counters for consecutive '1's

	// Loop through each character in string 'a' starting from index 1
	for i := 1; i < len(a); i++ {
		if a[i] == a[i-1] { // Check if current character is same as previous character
			if a[i] == '1' {
				a[i] = '0' // If '1', change it to '0'
			} else {
				a[i] = '1' // If not '1', change it to '1'
			}
			a1++ // Increment counter for number of consecutive '1's
		}
	}

	// Loop through each character in string 'b' starting from the last character
	for i := len(b) - 1; i > 0; i-- {
		if b[i] == b[i-1] { // Check if current character is same as previous character
			if b[i-1] == '1' {
				b[i-1] = '0' // If '1', change it to '0'
			} else {
				b[i-1] = '1' // If not '1', change it to '1'
			}
			a2++ // Increment counter for number of consecutive '1's
		}
	}

	// Print the minimum number of consecutive '1's in strings 'a' and 'b'
	fmt.Fprintln(writer, min(a1, a2))
}

// min function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

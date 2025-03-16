
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// CColoringColorfully solves the problem
type CColoringColorfully struct {
}

// NewCColoringColorfully returns a new CColoringColorfully object
func NewCColoringColorfully() *CColoringColorfully {
	return new(CColoringColorfully)
}

// Solve the problem
func (c *CColoringColorfully) Solve(testNumber int, in io.Reader, out io.Writer) {
	// Read input
	s, _ := bufio.NewReader(in).ReadString('\n')
	s = strings.TrimSpace(s)

	// Create a StringBuilder object 'a' with the same string as 'x'
	a := strings.Builder{}
	a.WriteString(s)

	// Create a StringBuilder object 'b' with the same string as 'x'
	b := strings.Builder{}
	b.WriteString(s)

	// Initialize counter for number of consecutive '1's in string 'a'
	a1 := 0

	// Initialize counter for number of consecutive '1's in string 'b'
	a2 := 0

	// Loop through each character in string 'a' starting from index 1
	for i := 1; i < len(s); i++ {
		if a.String()[i] == a.String()[i-1] { // Check if current character is same as previous character
			if a.String()[i] == "1" {
				a.WriteByte('0')
			} else {
				a.WriteByte('1')
			}
			a1++ // Increment counter for number of consecutive '1's
		}
	}

	// Loop through each character in string 'b' starting from the last character
	for i := len(s) - 1; i > 0; i-- {
		if b.String()[i] == b.String()[i-1] { // Check if current character is same as previous character
			if b.String()[i-1] == "1" {
				b.WriteByte('0')
			} else {
				b.WriteByte('1')
			}
			a2++ // Increment counter for number of consecutive '1's
		}
	}

	// Print the minimum number of consecutive '1's in strings 'a' and 'b'
	fmt.Fprintln(out, min(a1, a2))
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// main function
func main() {
	testCases := 1

	for i := 0; i < testCases; i++ {
		// Create a new CColoringColorfully object
		c := NewCColoringColorfully()

		// Solve the problem
		c.Solve(i, os.Stdin, os.Stdout)
	}
}


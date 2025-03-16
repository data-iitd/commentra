
package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read input and split into two strings a and b, removing the trailing newline
	a, b := input()[:len(input())-1], input()[:len(input())-1]

	// Determine the maximum length of the two strings
	x := max(len(a), len(b))

	// Right-justify 'a' and left-justify 'b' to ensure both have the same length, padding with '0'
	a = a.rjust(x, '0')
	b = b.ljust(x, '0')

	// Initialize an empty string to store the result and a carry variable
	s := ""
	c := 0

	// Iterate over each digit from the least significant to the most significant
	for i := 0; i < x; i++ {
		// Calculate the sum of the corresponding digits and the carry
		d := int(b[i]) + int(a[x-i-1]) + c

		// Check if the sum exceeds 9, which requires a carry
		if d > 9 {
			s += string(d)[1:]  // Append the last digit of the sum to the result
			c = 1  // Set carry to 1 for the next iteration
		} else {
			s += string(d)  // Append the sum to the result
			c = 0  // Reset carry to 0
		}
	}

	// If there's a carry left after the last addition, append '1' to the result
	if c == 1 {
		s += "1"
	}

	// Print the final result, reversing the string to get the correct order and converting to int to remove leading zeros
	fmt.Println(int(s[strings.LastIndex(s, "")-1:]))
}

// max returns the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// input reads a line of input from stdin and returns it as a string
func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

// rjust returns a string right-justified in a field of length w, padding with pad
func (s string) rjust(w int, pad string) string {
	return strings.Repeat(pad, w-len(s)) + s
}

// ljust returns a string left-justified in a field of length w, padding with pad
func (s string) ljust(w int, pad string) string {
	return s + strings.Repeat(pad, w-len(s))
}

// END-OF-CODE

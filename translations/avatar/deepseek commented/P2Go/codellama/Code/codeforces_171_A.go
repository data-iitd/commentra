
package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read input and split into two strings, a and b
	a, b := input()

	// Determine the maximum length of the two strings
	x := max(len(a), len(b))

	// Pad the shorter string with zeros on the left
	a = a.rjust(x, '0')

	// Pad the shorter string with zeros on the right
	b = b.ljust(x, '0')

	// Initialize an empty string to store the result
	s := ""

	// Initialize carry to 0
	c := 0

	// Loop through each digit from right to left
	for i := 0; i < x; i++ {
		// Add the corresponding digits from a and b along with the carry
		d := int(b[i]) + int(a[x-i-1]) + c

		// If the sum is greater than 9, set carry to 1 and append the tens digit
		if d > 9 {
			s += string(d)[1]
			c = 1
		} else {
			// Otherwise, append the sum and set carry to 0
			s += string(d)
			c = 0
		}
	}

	// If there's a carry left after the final addition, append '1'
	if c == 1 {
		s += "1"
	}

	// Reverse the result string and print it as an integer
	fmt.Println(strings.Reverse(s))
}

func input() (string, string) {
	var a, b string
	fmt.Scan(&a, &b)
	return a, b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
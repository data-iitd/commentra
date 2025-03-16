package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	var a, b string
	fmt.Scan(&a, &b)

	// Finding the maximum length between 'a' and 'b'
	x := max(len(a), len(b))

	// Padding zeros to the shorter string
	a = padLeft(a, x, '0')
	b = padRight(b, x, '0')

	s := ""
	c := 0

	// Iterating through each index
	for i := 0; i < x; i++ {
		d := int(b[i]-'0') + int(a[x-i-1]-'0') + c

		if d > 9 {
			s += string(d%10 + '0')
			c = 1
		} else {
			s += string(d + '0')
			c = 0
		}
	}

	// If there is still a carry left, add it to the result string 's'
	if c == 1 {
		s += "1"
	}

	// Printing the final result after removing the leading zeros (if any)
	result := strings.TrimLeft(s, "0")
	if result == "" {
		result = "0"
	}
	fmt.Println(result)
}

// Function to pad a string on the left
func padLeft(s string, length int, pad rune) string {
	return strings.Repeat(string(pad), length-len(s)) + s
}

// Function to pad a string on the right
func padRight(s string, length int, pad rune) string {
	return s + strings.Repeat(string(pad), length-len(s))
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	var a, b string
	fmt.Scanln(&a, &b)

	// Determine the maximum length of the two strings
	x := max(len(a), len(b))

	// Pad the shorter string with zeros on the left
	a = padLeft(a, x)
	// Pad the shorter string with zeros on the right
	b = padRight(b, x)

	// Initialize an empty string to store the result
	s := ""
	// Initialize carry to 0
	c := 0

	// Loop through each digit from right to left
	for i := 0; i < x; i++ {
		// Add the corresponding digits from a and b along with the carry
		d := int(b[i]-'0') + int(a[x-i-1]-'0') + c

		// If the sum is greater than 9, set carry to 1 and append the tens digit
		if d > 9 {
			s += string(d%10 + '0')
			c = 1
		} else {
			// Otherwise, append the sum and set carry to 0
			s += string(d + '0')
			c = 0
		}
	}

	// If there's a carry left after the final addition, append '1'
	if c == 1 {
		s += "1"
	}

	// Reverse the result string and print it as an integer
	result := reverse(s)
	fmt.Println(result)
}

// Function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// Function to pad a string with zeros on the left
func padLeft(s string, length int) string {
	return strings.Repeat("0", length-len(s)) + s
}

// Function to pad a string with zeros on the right
func padRight(s string, length int) string {
	return s + strings.Repeat("0", length-len(s))
}

// Function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Use bufio for faster input
	reader := bufio.NewReader(os.Stdin)

	// Read input and split into two strings a and b
	input, _ := reader.ReadString('\n')
	parts := strings.Fields(strings.TrimSpace(input))
	a, b := parts[0], parts[1]

	// Determine the maximum length of the two strings
	x := max(len(a), len(b))

	// Right-justify 'a' and left-justify 'b' to ensure both have the same length, padding with '0'
	a = rightPad(a, x, '0')
	b = leftPad(b, x, '0')

	// Initialize an empty string to store the result and a carry variable
	s := ""
	c := 0

	// Iterate over each digit from the least significant to the most significant
	for i := 0; i < x; i++ {
		// Calculate the sum of the corresponding digits and the carry
		d := int(b[i]-'0') + int(a[x-i-1]-'0') + c

		// Check if the sum exceeds 9, which requires a carry
		if d > 9 {
			s += string(d%10 + '0') // Append the last digit of the sum to the result
			c = 1                     // Set carry to 1 for the next iteration
		} else {
			s += string(d + '0')      // Append the sum to the result
			c = 0                     // Reset carry to 0
		}
	}

	// If there's a carry left after the last addition, append '1' to the result
	if c == 1 {
		s += "1"
	}

	// Print the final result, reversing the string to get the correct order and converting to int to remove leading zeros
	result, _ := strconv.Atoi(reverse(s))
	fmt.Println(result)
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to right pad a string with a character
func rightPad(s string, length int, pad rune) string {
	for len(s) < length {
		s = string(pad) + s
	}
	return s
}

// Helper function to left pad a string with a character
func leftPad(s string, length int, pad rune) string {
	for len(s) < length {
		s = s + string(pad)
	}
	return s
}

// Helper function to reverse a string
func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

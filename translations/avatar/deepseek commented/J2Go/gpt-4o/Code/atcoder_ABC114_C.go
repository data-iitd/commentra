package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N) // Reading an integer N from the user
	i := int64(357) // Initializing the starting number
	c := 0 // Initializing the counter for valid numbers

	// Main loop to find numbers containing '3', '5', and '7'
	for i <= int64(N) {
		s := strconv.FormatInt(i, 10) // Converting the current number to a string
		if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") {
			c++ // Incrementing the counter if all required digits are present
		}

		// Building a new number by replacing the last digit
		var sb strings.Builder
		f := false
		for j := len(s) - 1; j >= 0; j-- {
			a := s[j]
			if f {
				sb.WriteByte(a) // Appending characters after the replacement
			} else {
				if a == '3' {
					sb.WriteByte('5') // Replacing '3' with '5'
					f = true
				} else if a == '5' {
					sb.WriteByte('7') // Replacing '5' with '7'
					f = true
				} else {
					sb.WriteByte('3') // Replacing other digits with '3'
				}
			}
		}
		if !f {
			sb.WriteByte('3') // Appending '3' if no replacements were made
		}

		// Reversing the new number and converting it back to a long
		newNumberStr := sb.String()
		i, _ = strconv.ParseInt(reverseString(newNumberStr), 10, 64)
	}

	// Output the result
	fmt.Println(c) // Printing the count of valid numbers
}

// Helper function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

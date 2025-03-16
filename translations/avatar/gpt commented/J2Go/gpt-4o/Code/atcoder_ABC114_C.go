package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read an integer N from the user
	var N int
	fmt.Scan(&N)

	// Initialize a long variable i starting from 357
	i := int64(357)

	// Initialize a counter to keep track of valid numbers
	c := 0

	// Loop until i exceeds N
	for i <= int64(N) {
		// Convert the current number i to a String
		s := strconv.FormatInt(i, 10)

		// Check if the string contains '3', '5', and '7'
		if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") {
			c++ // Increment the counter if all digits are present
		}

		// Create a StringBuilder to construct a new number
		var sb strings.Builder
		f := false // Flag to indicate if a replacement has occurred

		// Iterate through the digits of the number in reverse order
		for j := 0; j < len(s); j++ {
			a := s[len(s)-1-j] // Get the current digit

			// If a replacement has occurred, append the digit as is
			if f {
				sb.WriteByte(a)
			} else {
				// Replace '3' with '5' and set the flag
				if a == '3' {
					sb.WriteByte('5')
					f = true
				} else if a == '5' { // Replace '5' with '7' and set the flag
					sb.WriteByte('7')
					f = true
				} else { // If it's neither, append '3'
					sb.WriteByte('3')
				}
			}
		}

		// If no replacement occurred, append '3' to the StringBuilder
		if !f {
			sb.WriteByte('3')
		}

		// Reverse the constructed number and parse it back to long
		reversed := reverseString(sb.String())
		i, _ = strconv.ParseInt(reversed, 10, 64)
	}

	// Print the total count of valid numbers found
	fmt.Println(c)
}

// Function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// <END-OF-CODE>

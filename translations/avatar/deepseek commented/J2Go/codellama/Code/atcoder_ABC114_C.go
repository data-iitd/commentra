package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int // Declaring an integer N to read input
	fmt.Scan(&N) // Reading an integer N from the user
	i := 357 // Initializing the starting number
	c := 0 // Initializing the counter for valid numbers

	// Main loop to find numbers containing '3', '5', and '7'
	for i <= N {
		s := strconv.Itoa(int(i)) // Converting the current number to a string
		if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") {
			c++ // Incrementing the counter if all required digits are present
		}

		// Building a new number by replacing the last digit
		sb := "" // Initializing an empty string to build the new number
		f := false
		for j := 0; j < len(s); j++ {
			a := s[len(s) - 1 - j]
			if f {
				sb += string(a) // Appending characters after the replacement
			} else {
				if a == '3' {
					sb += "5" // Replacing '3' with '5'
					f = true
				} else if a == '5' {
					sb += "7" // Replacing '5' with '7'
					f = true
				} else {
					sb += "3" // Replacing other digits with '3'
				}
			}
		}
		if !f {
			sb += "3" // Appending '3' if no replacements were made
		}

		// Reversing the new number and converting it back to a long
		sb2 := ""
		for j := len(sb) - 1; j >= 0; j-- {
			sb2 += string(sb[j])
		}
		i, _ = strconv.ParseInt(sb2, 10, 64)
	}

	// Output the result
	fmt.Println(c) // Printing the count of valid numbers
}


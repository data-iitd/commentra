package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare a static Scanner object for input
	var scanner *bufio.Scanner
	scanner = bufio.NewScanner(os.Stdin)

	// Read an integer N from the user
	var N int
	fmt.Scanf("%d", &N)

	// Initialize a long variable i starting from 357
	var i int64 = 357

	// Initialize a counter to keep track of valid numbers
	var c int = 0

	// Loop until i exceeds N
	for i <= N {
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
				}
				// Replace '5' with '7' and set the flag
				else if a == '5' {
					sb.WriteByte('7')
					f = true
				}
				// If it's neither, append '3'
				else {
					sb.WriteByte('3')
				}
			}
		}

		// If no replacement occurred, append '3' to the StringBuilder
		if!f {
			sb.WriteByte('3')
		}

		// Reverse the constructed number and parse it back to long
		sb2 := strings.NewReversedBuilder(sb.String())
		i, _ = strconv.ParseInt(sb2.String(), 10, 64)
	}

	// Print the total count of valid numbers found
	fmt.Println(c)
}


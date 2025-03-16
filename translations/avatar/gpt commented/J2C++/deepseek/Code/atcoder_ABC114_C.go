package main

import (
	"fmt"
	"strconv"
)

// Declare a global Scanner object for input
var scanner *bufio.Scanner

func main() {
	// Initialize the Scanner object to read input from the console
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read an integer N from the user
	N := gi()

	// Initialize a long variable i starting from 357
	i := int64(357)

	// Initialize a counter to keep track of valid numbers
	c := 0

	// Loop until i exceeds N
	for i <= int64(N) {
		// Convert the current number i to a String
		s := strconv.FormatInt(i, 10)

		// Check if the string contains '3', '5', and '7'
		if contains(s, "3") && contains(s, "5") && contains(s, "7") {
			c++ // Increment the counter if all digits are present
		}

		// Create a StringBuilder to construct a new number
		var sb strings.Builder
		f := false // Flag to indicate if a replacement has occurred

		// Iterate through the digits of the number in reverse order
		for j := len(s) - 1; j >= 0; j-- {
			a := s[j] // Get the current digit

			// If a replacement has occurred, append the digit as is
			if f {
				sb.WriteByte(a)
			} else {
				// Replace '3' with '5' and set the flag
				if a == '3' {
					sb.WriteString("5")
					f = true
				}
				// Replace '5' with '7' and set the flag
				else if a == '5' {
					sb.WriteString("7")
					f = true
				}
				// If it's neither, append '3'
				else {
					sb.WriteByte('3')
				}
			}
		}

		// If no replacement occurred, append '3' to the StringBuilder
		if !f {
			sb.WriteByte('3')
		}

		// Reverse the constructed number and parse it back to long
		reversed := reverse(sb.String())
		i, _ = strconv.ParseInt(reversed, 10, 64)
	}

	// Print the total count of valid numbers found
	fmt.Println(c)
}

// Method to read a String input from the user
func gs() string {
	scanner.Scan()
	return scanner.Text()
}

// Method to read an integer input from the user
func gi() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// Method to read a long input from the user
func gl() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

// Method to read a double input from the user
func gd() float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

// Helper function to check if a string contains a substring
func contains(s, substr string) bool {
	return strings.Contains(s, substr)
}

// Helper function to reverse a string
func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
<END-OF-CODE>.
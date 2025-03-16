package main

import (
	"fmt"
)

func main() {
	// Declare a string variable to hold the input
	var s string
	// Read the input string from standard input
	fmt.Scan(&s)

	// Initialize variables to track the maximum length of valid characters and the current length
	max_tmp := 0
	max := 0

	// Iterate over each character in the input string
	for i := 0; i < len(s); i++ {
		// Flag to indicate if a non-valid character is encountered
		flag := false

		// Check if the current character is one of the valid DNA bases
		switch string(s[i]) {
		case "A", "C", "T", "G":
			// Increment the temporary count for valid characters
			max_tmp++
		default:
			// Set the flag to true if a non-valid character is found
			flag = true
		}

		// Check if we are at the last character of the string
		if i == len(s)-1 {
			// Set the flag to true to handle the end of the string
			flag = true
		}

		// If a non-valid character was found or we reached the end of the string
		if flag == true {
			// Update the maximum length if the current temporary length is greater
			if max < max_tmp {
				max = max_tmp
			}
			// Reset the temporary length counter
			max_tmp = 0
		}
	}

	// Print the maximum length of consecutive valid characters found
	fmt.Println(max)
}

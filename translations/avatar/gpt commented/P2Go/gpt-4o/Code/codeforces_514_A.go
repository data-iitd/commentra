package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Get user input
	var ip string
	fmt.Scan(&ip)

	// Initialize an empty string to store the transformed number
	st := ""

	// Check if the input length is not equal to 1
	if len(ip) != 1 {
		// If the first character is '9', keep it and remove it from the input
		if ip[0] == '9' {
			st = "9" // Start the output string with '9'
			ip = ip[1:] // Remove the first character from the input
		}

		// Iterate through each character in the remaining input
		for _, i := range ip {
			digit := int(i - '0') // Convert character to integer
			// If the digit is greater than 4, calculate its complement to 9
			if digit > 4 {
				n := 9 - digit // Calculate the complement
				st += strconv.Itoa(n) // Append the complement to the output string
			} else {
				// If the digit is 4 or less, keep it unchanged
				st += string(i) // Append the original digit to the output string
			}
		}
	} else {
		// If the input length is 1, simply assign it to the output
		st = ip
	}

	// Print the final transformed number as an integer
	result, _ := strconv.Atoi(st)
	fmt.Println(result)
}

// <END-OF-CODE>

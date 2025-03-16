package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scanln(&s) // Take an input string from the user
	result := ""   // Initialize an empty string to store the result
	i := 0         // Initialize the index to 0

	// Start a while loop that will run as long as the index i is less than the length of the input string s
	for i < len(s) {
		if s[i] == '.' { // Check if the current character is a period
			result += "0" // Append '0' to the result if the current character is a period
		} else {
			i++ // Increment the index i by 1
			if i < len(s) && s[i] == '.' { // Check the next character in the string
				result += "1" // Append '1' to the result if the next character is a period
			} else {
				result += "2" // Append '2' to the result if the next character is not a period
			}
		}
		i++ // Increment the index i by 1 to move to the next character in the string
	}

	fmt.Println(result) // Print the final result
}

// <END-OF-CODE>

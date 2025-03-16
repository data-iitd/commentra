package main

import (
	"fmt"
	"strings"
)

func main() {
	// Define the array of substrings to check against
	divide := []string{"dream", "dreamer", "erase", "eraser"}

	var S string
	// Read the input string from the user
	fmt.Scan(&S)

	// Reverse the input string to facilitate checking from the end
	S = reverseString(S)
	// Reverse each of the substrings in the divide array for matching
	for i := range divide {
		divide[i] = reverseString(divide[i])
	}

	// Initialize a flag to determine if the string can be fully divided
	can := true
	// Start checking the string from the beginning
	for i := 0; i < len(S); {
		can2 := false // Flag to check if we can divide with any of the substrings
		// Iterate through each substring in the divide array
		for _, d := range divide {
			// Check if the current substring matches the beginning of the remaining string
			if strings.HasPrefix(S[i:], d) { // If we can divide with d
				can2 = true // Set the flag to true
				i += len(d) // Move the index forward by the length of the matched substring
				break       // Break to avoid checking other substrings once a match is found
			}
		}
		// If no substring matched, set the can flag to false and break the loop
		if !can2 { // If we couldn't divide the string
			can = false
			break
		}
	}

	// Output the result based on whether the string can be fully divided
	if can {
		fmt.Println("YES") // If it can be divided, print "YES"
	} else {
		fmt.Println("NO") // Otherwise, print "NO"
	}
}

// Function to reverse a string
func reverseString(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// <END-OF-CODE>

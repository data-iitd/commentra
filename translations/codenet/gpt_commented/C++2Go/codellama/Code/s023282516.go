package main

import (
	"fmt"
	"strings"
)

func main() {
	var S string
	fmt.Scan(&S)

	// Reverse the input string to facilitate checking from the end
	S = reverse(S)
	// Reverse each of the substrings in the divide array for matching
	for i := 0; i < len(divide); i++ {
		divide[i] = reverse(divide[i])
	}

	// Initialize a flag to determine if the string can be fully divided
	can := true
	// Start checking the string from the beginning
	for i := 0; i < len(S); {
		can2 := false // Flag to check if we can divide with any of the substrings
		// Iterate through each substring in the divide array
		for j := 0; j < len(divide); j++ {
			d := divide[j]
			// Check if the current substring matches the beginning of the remaining string
			if strings.HasPrefix(S[i:], d) { // If we can divide with d
				can2 = true // Set the flag to true
				i += len(d) // Move the index forward by the length of the matched substring
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

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// 
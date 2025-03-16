package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read the number of test cases
	var n int
	fmt.Scan(&n)

	// Process each test case
	for i := 0; i < n; i++ {
		var s string
		// Read the string for the current test case
		fmt.Scan(&s)

		// Initialize a map to store unique combinations of strings
		st := make(map[string]struct{})
		// Insert the original string into the map
		st[s] = struct{}{}

		// Generate combinations by splitting the string at different positions
		for j := 1; j < len(s); j++ {
			// Create the first part of the split string
			res := s[:j] // First part of the string
			res2 := s[j:] // Second part of the string

			// Create reversed versions of both parts
			t := reverse(res)  // Reverse the first part
			t2 := reverse(res2) // Reverse the second part

			// Insert various combinations of the parts and their reverses into the map
			st[t+t2] = struct{}{} // Original order
			st[t2+t] = struct{}{} // Reversed order

			st[t+res2] = struct{}{} // First part + second part
			st[res2+t] = struct{}{} // Second part + first part

			st[res+t2] = struct{}{} // First part + reversed second part
			st[t2+res] = struct{}{} // Reversed second part + first part

			st[res+res2] = struct{}{} // First part + second part (both original)
			st[res2+res] = struct{}{} // Second part + first part (both original)
		}

		// Output the number of unique combinations generated
		fmt.Println(len(st))
	}
}

// Function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// <END-OF-CODE>

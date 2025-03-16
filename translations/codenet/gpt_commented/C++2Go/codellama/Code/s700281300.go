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

		// Initialize a set to store unique combinations of strings
		st := make(map[string]bool)
		// Insert the original string into the set
		st[s] = true

		// Generate combinations by splitting the string at different positions
		for j := 1; j < len(s); j++ {
			// Create the first part of the split string
			res := s[:j]

			// Create the second part of the split string
			res2 := s[j:]

			// Create reversed versions of both parts
			t := res
			res = strings.Reverse(res) // Reverse the first part
			t2 := res2
			res2 = strings.Reverse(res2) // Reverse the second part

			// Insert various combinations of the parts and their reverses into the set
			st[t+t2] = true // Original order
			st[t2+t] = true // Reversed order

			st[t+res2] = true // First part + second part
			st[res2+t] = true // Second part + first part

			st[res+t2] = true // First part + reversed second part
			st[t2+res] = true // Reversed second part + first part

			st[res+res2] = true // First part + second part (both original)
			st[res2+res] = true // Second part + first part (both original)
		}

		// Output the number of unique combinations generated
		fmt.Println(len(st))
	}
}


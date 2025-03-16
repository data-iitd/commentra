package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int // number of strings to be processed

	// Read the number of strings from the standard input
	fmt.Scan(&n)

	// Iterate through each string
	for i := 0; i < n; i++ {
		var s string // string to be processed

		// Read the string from the standard input
		fmt.Scan(&s)

		// Create a map to store unique substrings
		st := make(map[string]struct{})

		// Process each substring of the string
		for j := 1; j < len(s); j++ {
			// Create the first substring
			res := s[:j]
			// Create the second substring
			res2 := s[j:]

			// Create two temporary strings by reversing the substrings
			t := reverse(res)
			t2 := reverse(res2)

			// Insert all possible combinations of the substrings and their reversed versions into the map
			st[t+t2] = struct{}{}
			st[t2+t] = struct{}{}
			st[t+res2] = struct{}{}
			st[res2+t] = struct{}{}
			st[res+t2] = struct{}{}
			st[t2+res] = struct{}{}
			st[res+res2] = struct{}{}
			st[res2+res] = struct{}{}
		}

		// Print the size of the map, which represents the number of unique substrings
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

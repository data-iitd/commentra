package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Step 1: Reading Input

	for i := 0; i < n; i++ { // Step 2: Processing Each Test Case
		var s string
		fmt.Scan(&s) // For each test case, read the string s.

		st := make(map[string]struct{}) // Step 3: Generating Substrings and Checking for Palindromes
		st[s] = struct{}{} // The first substring is inserted into the set.

		for j := 1; j < len(s); j++ { // The inner loop iterates over possible split points in the string s.
			res := reverse(s[:j]) // The first part of the string is reversed.
			res2 := reverse(s[j:]) // The second part of the string is reversed.

			t := res // The first part is concatenated with the reversed second part in both orders and added to the set.
			t2 := res2
			st[t+t2] = struct{}{}
			st[t2+t] = struct{}{}

			st[t+res2] = struct{}{} // The first part is concatenated with the reversed first part and added to the set.
			st[res2+t] = struct{}{}

			st[res+t2] = struct{}{} // The reversed first part is concatenated with the second part and added to the set.
			st[t2+res] = struct{}{}

			st[res+res2] = struct{}{} // The reversed first and second parts are concatenated in both orders and added to the set.
			st[res2+res] = struct{}{}
		}

		fmt.Println(len(st)) // Step 4: Outputting the Result
	}

	// Step 5: End of Program
}

// Helper function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// <END-OF-CODE>

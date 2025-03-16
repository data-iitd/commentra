package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Step 1: Reading Input - The program starts by reading an integer n which represents the number of test cases.

	for i := 0; i < n; i++ { // Step 2: Processing Each Test Case - The outer loop rep(i,n) iterates over each test case.
		var s string
		fmt.Scan(&s) // For each test case, the program reads a string s.

		st := make(map[string]bool) // Step 3: Generating Substrings and Checking for Palindromes - A set st is used to store unique substrings.
		st[s] = true // The first substring is inserted into the set.

		for j := 1; j < len(s); j++ { // The inner loop REP(j,1,s.size()) iterates over possible split points in the string s.
			res := s[:j] // The first part of the string is extracted and reversed.
			res = strings.Reverse(res)

			res2 := s[j:] // The second part of the string is extracted and reversed.
			res2 = strings.Reverse(res2)

			t := res + res2 // The first part is concatenated with the reversed second part in both orders and added to the set.
			st[t] = true
			st[res2+res] = true

			st[res+res2] = true // The first part is concatenated with the reversed first part and added to the set.
			st[res2+res] = true

			st[res+res2] = true // The reversed first part is concatenated with the second part and added to the set.
			st[res2+res] = true

			st[res+res2] = true // The reversed first and second parts are concatenated in both orders and added to the set.
			st[res2+res] = true
		}

		fmt.Println(len(st)) // Step 4: Outputting the Result - After processing all split points for a string, the size of the set st is printed.
	}
}


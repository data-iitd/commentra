
package main

import (
	"bufio"
	"fmt"
	"os"
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

		// Create an empty set to store unique substrings
		st := make(map[string]bool)

		// Process each substring of the string
		for j := 1; j < len(s); j++ {
			// Create a stringstream to store the substring
			ss := ""

			// Iterate through the first j characters of the string
			for k := 0; k < j; k++ {
				// Add the character to the stringstream
				ss += string(s[k])
			}

			// Get the substring as a string from the stringstream
			res := ss

			// Create another stringstream to process the remaining characters of the string
			ss2 := ""

			// Iterate through the remaining characters of the string
			for k := j; k < len(s); k++ {
				// Add the character to the stringstream
				ss2 += string(s[k])
			}

			// Get the substring as a string from the stringstream
			res2 := ss2

			// Create two temporary strings by reversing the substrings
			t := res
			res = Reverse(res)
			t2 := res2
			res2 = Reverse(res2)

			// Insert all possible combinations of the substrings and their reversed versions into the set
			st[t+t2] = true
			st[t2+t] = true
			st[t+res2] = true
			st[res2+t] = true
			st[res+t2] = true
			st[t2+res] = true
			st[res+res2] = true
			st[res2+res] = true
		}

		// Print the size of the set, which represents the number of unique substrings
		fmt.Println(len(st))
	}
}

// Reverse returns the reverse of the input string
func Reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// 
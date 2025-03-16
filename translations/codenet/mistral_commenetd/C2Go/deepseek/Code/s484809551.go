package main

import (
	"fmt"
	"strings"
)

func main() {
	// Define pattern base string
	patternBase := "keyence"
	var top, bottom [8]byte
	var S [101]byte

	// Read input string from standard input
	fmt.Scanln(&S)

	// Calculate length of input string
	len := len(S)
	found := false

	// Loop through each character in pattern base string
	for offset := 0; offset < len(patternBase); offset++ {
		// Copy substring up to current character to top variable
		copy(top[:], patternBase[:offset])
		top[offset] = 0

		// Copy substring from current character to end of pattern base string to bottom variable
		copy(bottom[:], patternBase[offset:])
		bottom[len(patternBase)-offset] = 0

		// Search for top substring in input string
		topSearch := strings.Index(string(S[:]), string(top[:]))

		// If top substring is found
		if topSearch != -1 {
			// Search for bottom substring after top substring in input string
			bottomSearch := strings.LastIndex(string(S[topSearch+offset:]), string(bottom[:]))

			// If bottom substring is found
			if bottomSearch != -1 {
				// Calculate number of separators between top and bottom substrings
				sepCount := 0

				// If topSearch is not the first occurrence of top substring in input string
				if topSearch != 0 {
					sepCount++
				}

				// If topSearch is not the same as bottomSearch
				if topSearch+offset != bottomSearch {
					sepCount++
				}

				// If bottomSearch is not the last character in input string
				if bottomSearch+len(bottom) != len {
					sepCount++
				}

				// If number of separators is less than or equal to 1
				if sepCount <= 1 {
					found = true
					break
				}
			}
		}
	}

	// Print output based on whether pattern is found or not
	if found {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}


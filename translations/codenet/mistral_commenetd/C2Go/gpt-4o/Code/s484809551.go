package main

import (
	"fmt"
	"strings"
)

// Define constants
const (
	N_MAX = 100
	P_MAX = 100
)

// Function to find the last occurrence of a substring in a string
func strrstr(s, pattern string) string {
	lastIndex := -1
	for i := 0; i <= len(s)-len(pattern); i++ {
		if s[i:i+len(pattern)] == pattern {
			lastIndex = i
		}
	}
	if lastIndex == -1 {
		return ""
	}
	return s[lastIndex:]
}

// Function to calculate the number of combinations of n items taken r at a time
func comb(n, r int) int {
	result := 1
	for i := 0; i < r; i++ {
		result *= n - i
		result /= i + 1
	}
	return result
}

// Function to find the greatest common divisor of two numbers
func gcd(m, n uint64) uint64 {
	var temp uint64
	for m%n != 0 {
		temp = n
		n = m % n
		m = temp
	}
	return n
}

func main() {
	// Define pattern base string
	patternBase := "keyence"
	var S string

	// Read input string from standard input
	fmt.Scan(&S)

	// Calculate length of input string
	lenS := len(S)
	found := false

	// Loop through each character in pattern base string
	for offset := 0; offset < len(patternBase); offset++ {
		// Copy substring up to current character to top variable
		top := patternBase[:offset]

		// Copy substring from current character to end of pattern base string to bottom variable
		bottom := patternBase[offset:]

		// Search for top substring in input string
		topSearch := strings.Index(S, top)

		// If top substring is found
		if topSearch != -1 {
			// Search for bottom substring after top substring in input string
			bottomSearch := strrstr(S[topSearch+offset:], bottom)

			// If bottom substring is found
			if bottomSearch != "" {
				// Calculate number of separators between top and bottom substrings
				sepCount := 0

				// If topSearch is not the first occurrence of top substring in input string
				if topSearch != 0 {
					sepCount++
				}

				// If topSearch is not the same as bottomSearch
				if S[topSearch+offset:] != bottomSearch {
					sepCount++
				}

				// If bottomSearch is not the last character in input string
				if bottomSearch[len(bottom):] != "" {
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

// <END-OF-CODE>

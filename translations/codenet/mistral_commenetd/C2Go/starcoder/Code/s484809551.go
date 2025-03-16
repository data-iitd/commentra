
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strings"
)

// Define constants
const (
	N_MAX = 100
	P_MAX = 100
	DP_ARRAY_SIZE = N_MAX * P_MAX / 32 + 1
)

// Define helper functions
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func abss(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}

// Function to find the last occurrence of a substring in a string
func strrstr(s, p string) string {
	offset := 0
	lastP := ""

	searchResult := ""
	for searchResult = strings.Index(s[offset:], p); searchResult!= -1 && s[offset]!= '\0'; {
		lastP = s[offset : offset+searchResult]
		offset++
	}

	return lastP
}

// Function to compare two pointers for qsort
func compare_f(a, b interface{}) int {
<<<<<<< HEAD
	return int(*(*uint64)(a)) < int(*(*uint64)(b))
=======
	return a.(int) < b.(int)
>>>>>>> 98c87cb78a (data updated)
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
	temp := uint64(0)

	for m%n!= 0 {
		temp = n
		n = m % n
		m = temp
	}

	return n
}

func main() {
	// Define pattern base string
	patternBase := "keyence"
	top := make([]byte, 8)
	bottom := make([]byte, 8)
	S := make([]byte, 101)

	// Read input string from standard input
	fmt.Fscanf(os.Stdin, "%s", &S)

	// Calculate length of input string
	len := len(S)
	found := false

	// Loop through each character in pattern base string
	for offset := 0; offset < len(patternBase); offset++ {
		// Copy substring up to current character to top variable
		copy(top, patternBase[:offset])
		top[offset] = 0

		// Copy substring from current character to end of pattern base string to bottom variable
		copy(bottom, patternBase[offset:])
		bottom[len(patternBase)-offset] = 0

		// Search for top substring in input string
		topSearch := strings.Index(string(S), string(top))

		// If top substring is found
		if topSearch!= -1 {
			// Search for bottom substring after top substring in input string
			bottomSearch := strrstr(string(S[topSearch+offset:]), string(bottom))

			// If bottom substring is found
			if bottomSearch!= "" {
				// Calculate number of separators between top and bottom substrings
				sepCount := 0

				// If topSearch is not the first occurrence of top substring in input string
				if topSearch!= 0 {
					sepCount++
				}

				// If topSearch is not the same as bottomSearch
<<<<<<< HEAD
				if string(topSearch+offset)!= bottomSearch {
					sepCount++
				}

				// If bottomSearch is not the last character in input string
				if string(bottomSearch+len(bottom))!= string(S) {
=======
				if topSearch+offset!= len(bottomSearch) {
					sepCount++
				}

				// If bottomSearch is not the last character in input(S)
				if len(bottomSearch)+len(bottom)!= len(S) {
>>>>>>> 98c87cb78a (data updated)
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
	fmt.Printf("%s\n", "YES" if found else "NO")
}


<<<<<<< HEAD

=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strings"
)

// Define constants for maximum sizes and array size for dynamic programming
const N_MAX = 100
const P_MAX = 100
const DP_ARRAY_SIZE = (N_MAX * P_MAX / 32 + 1)

// Define macros for common operations
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

// Function to find the last occurrence of a substring within a string
func strrstr(string, pattern string) string {
	offset := 0
	lastP := ""

	searchResult := ""
	// Loop to find the last occurrence of the pattern
	for searchResult = strings.Index(string[offset:], pattern); searchResult!= -1 && string[offset]!= '\0'; {
		lastP = searchResult
		offset++
	}

	return lastP
}

// Comparison function for qsort, comparing two size_t values
func compare_f(a, b *uint64) int {
	return int(*a) < int(*b)
}

// Function to calculate combinations C(n, r)
func comb(n, r int) int {
	result := 1

	// Calculate the combination using the formula
	for i := 0; i < r; i++ {
		result *= n - i
		result /= i + 1
	}

	return result
}

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(m, n uint64) uint64 {
	temp := uint64(0)

	// Euclidean algorithm to find GCD
	for m%n!= 0 {
		temp = n
		n = m % n
		m = temp
	}

	return n
}

// Main function to execute the program
func main() {
	patternBase := "keyence" // Define the pattern to search for
	top := make([]byte, 8)
	bottom := make([]byte, 8)
	S := make([]byte, 101)

	// Read the input string
	fmt.Fscanf(os.Stdin, "%s", &S)

	len := len(S) // Get the length of the input string
	found := false  // Flag to indicate if the pattern is found

	// Loop through each possible split point in the pattern
	for offset := 0; offset < len(patternBase); offset++ {
		// Split the pattern into top and bottom parts
		copy(top, patternBase[:offset])
		top[offset] = 0
		copy(bottom, patternBase[offset:])
		bottom[len(patternBase)-offset] = 0

		// Search for the top part in the input string
		topSearch := strings.Index(string(S), string(top))
		if topSearch!= -1 {
			// Search for the bottom part after the found top part
			bottomSearch := strrstr(string(S[topSearch+offset:]), string(bottom))
			if bottomSearch!= -1 {
				sepCount := 0

				// Count the number of separators between top and bottom parts
				if topSearch!= 0 {
					sepCount++
				}
				if topSearch+offset!= bottomSearch {
					sepCount++
				}
				if bottomSearch+len(bottom)!= len(S) {
					sepCount++
				}

				// Check if the number of separators is less than or equal to 1
				if sepCount <= 1 {
					found = true
					break
				}
			}
		}
	}

	// Output the result based on whether the pattern was found
<<<<<<< HEAD
	fmt.Printf("%s\n", "YES" if found else "NO")
=======
	fmt.Println((found? "YES" : "NO"))
>>>>>>> 98c87cb78a (data updated)
}


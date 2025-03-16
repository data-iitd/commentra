#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

// Define constants for maximum sizes and array size for dynamic programming
const N_MAX = 100
const P_MAX = 100
const DP_ARRAY_SIZE = N_MAX * P_MAX / 32 + 1

// Define macros for common operations
const MIN = (a, b) => (a < b ? a : b)
const MAX = (a, b) => (a > b ? a : b)
const ABS = (a) => (a < 0 ? -a : a)
const ABSS = (a, b) => (a > b ? a - b : b - a)

// Function to find the last occurrence of a substring within a string
func strrstr(string, pattern string) string {
	offset := 0
	lastP := ""

	searchResult := ""
	// Loop to find the last occurrence of the pattern
	for searchResult = strings.Index(string[offset:], pattern); searchResult != -1 && string[offset] != '\0'; {
		lastP = searchResult // Update last found position
		offset++ // Move offset to search for further occurrences
	}

	return lastP // Return the last found position
}

// Comparison function for qsort, comparing two size_t values
func compare_f(a, b interface{}) int {
	return *a.(size_t) < *b.(size_t) ? -1 : 1 // Return comparison result
}

// Function to calculate combinations C(n, r)
func comb(n, r size_t) size_t {
	result := 1

	// Calculate the combination using the formula
	for i := 0; i < r; i++ {
		result *= n - i // Multiply by decreasing values of n
		result /= i + 1 // Divide by increasing values of r
	}

	return result // Return the result
}

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(m, n uint64) uint64 {
	temp := 0

	// Euclidean algorithm to find GCD
	for m % n != 0 {
		temp = n
		n = m % n // Update n to the remainder
		m = temp // Update m to the previous n
	}

	return n // Return the GCD
}

// Main function to execute the program
func main() {
	const patternBase = "keyence" // Define the pattern to search for
	top := make([]byte, 8) // Buffers to hold split parts of the pattern
	bottom := make([]byte, 8)
	S := make([]byte, 101) // Buffer to hold the input string

	// Read the input string
	fmt.Scanf("%s", &S)

	const len = len(S) // Get the length of the input string
	found := false // Flag to indicate if the pattern is found

	// Loop through each possible split point in the pattern
	for offset := 0; offset < len(patternBase); offset++ {
		// Split the pattern into top and bottom parts
		copy(top, patternBase[:offset])
		top[offset] = '\0' // Null-terminate the top part
		copy(bottom, patternBase[offset:])
		bottom[len(patternBase) - offset] = '\0' // Null-terminate the bottom part

		// Search for the top part in the input string
		topSearch := strings.Index(string(S), string(top))
		if topSearch != -1 {
			// Search for the bottom part after the found top part
			bottomSearch := strrstr(string(S[topSearch:]), string(bottom))
			if bottomSearch != "" {
				sepCount := 0 // Counter for separators

				// Count the number of separators between top and bottom parts
				if topSearch != 0 {
					sepCount++ // Increment if there's text before the top part
				}
				if &(S[topSearch + offset]) != bottomSearch {
					sepCount++ // Increment if there's text between top and bottom parts
				}
				if bottomSearch[len(bottom)] != '\0' {
					sepCount++ // Increment if there's text after the bottom part
				}

				// Check if the number of separators is less than or equal to 1
				if sepCount <= 1 {
					found = true // Set found flag to true
					break // Exit the loop as the pattern is found
				}
			}
		}
	}

	// Output the result based on whether the pattern was found
	fmt.Println((found ? "YES" : "NO"))

	return 0 // Return success
}


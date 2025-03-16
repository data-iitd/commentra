package main

import (
	"fmt"
	"strings"
)

// Define a constant for the maximum size of the strings
const M = 1010

// Declare character arrays to hold the input strings
var a [M]byte
var b [M]byte

// Declare variables for the lengths of the strings and the minimum answer
var n, m, ans int

func main() {
	// Read the first string into array 'a' starting from index 1
	fmt.Scanf("%s", &a[1:])
	// Calculate the length of the first string
	n = len(a[1:])

	// Read the second string into array 'b' starting from index 1
	fmt.Scanf("%s", &b[1:])
	// Calculate the length of the second string
	m = len(b[1:])

	// Iterate over all possible starting positions in 'a' where 'b' can fit
	for i := 1; i+m-1 <= n; i++ {
		// Initialize a variable to count the number of mismatches
		sum := 0

		// Compare the substring of 'a' with 'b' character by character
		for j := 1; j <= m; j++ {
			// Increment the mismatch count if characters do not match
			if a[i+j-1] != b[j] {
				sum++
			}
		}

		// Update the minimum number of mismatches found
		ans = min(ans, sum)
	}

	// Output the minimum number of mismatches
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 
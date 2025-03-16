package main

import (
	"fmt"
)

// Define long long type for large integers
type ll int64

// Declare variables
var n, k, ans ll = 0, 0, 0
var s string
var L ll = 0
var cnt ll = 0

func main() {
	// Read the number of characters (n) and the maximum number of operations (k)
	fmt.Scan(&n, &k)

	// Read the string of characters
	fmt.Scan(&s)

	// Initialize L with the first character of the string
	L = ll(s[0])
	cnt = 0 // Initialize a counter for consecutive characters

	// Iterate through the string starting from the second character
	for i := 1; i < n; i++ {
		// If the current character is the same as the last character
		if L == ll(s[i]) {
			cnt++ // Increment the counter
		} else {
			// If the character changes, update L and add the count to ans
			L = ll(s[i])
			ans += cnt // Add the count of consecutive characters to ans
			ans2++ // Increment the number of distinct character groups
			cnt = 0 // Reset the counter for the new character
		}
	}

	// After the loop, add the count of the last group of characters to ans
	ans += cnt
	ans2++ // Increment for the last group

	// Output the final result: total operations plus the minimum of 2*k or (number of groups - 1)
	fmt.Println(ans + min(2*k, ans2-1))
}

func min(a, b ll) ll {
	if a < b {
		return a
	}
	return b
}

// 
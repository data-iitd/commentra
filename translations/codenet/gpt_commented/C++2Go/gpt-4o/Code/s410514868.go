package main

import (
	"fmt"
	"math"
)

func main() {
	var n, k int64
	var ans, L, ans2 int64
	var s string

	// Read the number of characters (n) and the maximum number of operations (k)
	fmt.Scan(&n, &k)

	// Read the string of characters
	fmt.Scan(&s)

	// Initialize L with the first character of the string
	L = int64(s[0])
	cnt := int64(0) // Initialize a counter for consecutive characters

	// Iterate through the string starting from the second character
	for i := int64(1); i < n; i++ {
		// If the current character is the same as the last character
		if L == int64(s[i]) {
			cnt++ // Increment the counter
		} else {
			// If the character changes, update L and add the count to ans
			L = int64(s[i])
			ans += cnt // Add the count of consecutive characters to ans
			ans2++     // Increment the number of distinct character groups
			cnt = 0    // Reset the counter for the new character
		}
	}

	// After the loop, add the count of the last group of characters to ans
	ans += cnt
	ans2++ // Increment for the last group

	// Output the final result: total operations plus the minimum of 2*k or (number of groups - 1)
	fmt.Println(ans + int64(math.Min(float64(2*k), float64(ans2-1))))
}

// <END-OF-CODE>

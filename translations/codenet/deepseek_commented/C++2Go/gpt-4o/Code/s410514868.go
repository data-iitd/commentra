package main

import (
	"fmt"
	"math"
)

func main() {
	var n, k int64
	var s string
	var ans, cnt, ans2 int64

	// Reading the input values for n and k, and the string s
	fmt.Scan(&n, &k)
	fmt.Scan(&s)

	// Initializing L with the first character of s
	L := s[0]
	cnt = 0

	// Loop through the string starting from the second character
	for i := int64(1); i < n; i++ {
		// If the current character is the same as L, increment cnt
		if L == s[i] {
			cnt++
		} else {
			// Update L to the new character, add cnt to ans, increment ans2, and reset cnt
			L = s[i]
			ans += cnt
			ans2++
			cnt = 0
		}
	}

	// Add the final count to ans and increment ans2
	ans += cnt
	ans2++

	// Calculate the output as ans + min(2*k, ans2-1) and print it
	fmt.Println(ans + int64(math.Min(float64(2*k), float64(ans2-1))))
}

// <END-OF-CODE>

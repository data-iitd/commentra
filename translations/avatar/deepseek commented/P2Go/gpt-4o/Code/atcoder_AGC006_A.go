package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the integer input `n`
	s := make([]rune, n)
	t := make([]rune, n)

	for i := 0; i < n; i++ {
		var ch rune
		fmt.Scanf("%c", &ch) // Read the list `s` of length `n`
		s[i] = ch
	}
	for i := 0; i < n; i++ {
		var ch rune
		fmt.Scanf("%c", &ch) // Read the list `t` of length `n`
		t[i] = ch
	}

	// Check if the slices `s` and `t` are equal
	if string(s) == string(t) {
		fmt.Println(n) // If they are equal, print `n`
	} else {
		cnt := 0 // Initialize the counter `cnt` to 0
		// Compare elements of `s` and `t` starting from each index `i` of `s`
		for i := 0; i < n; i++ {
			for j := 0; j < n-i; j++ {
				// If a mismatch is found, break out of the inner loop
				if s[i+j] != t[j] {
					break
				}
				// If the end of the inner list is reached without breaking, set `cnt`
				if j == n-i-1 {
					cnt = n - i
				}
			}
		}
		// Print `2 * n - cnt`
		fmt.Println(2*n - cnt)
	}
}

// <END-OF-CODE>

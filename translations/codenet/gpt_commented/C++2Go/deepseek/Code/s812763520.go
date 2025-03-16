package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold the number of characters and the answer
	var n int
	var ans int
	var a, b, c string

	// Read the number of characters and the three strings from input
	fmt.Scan(&n)
	fmt.Scan(&a, &b, &c)

	// Iterate through each character index from 0 to n-1
	for i := 0; i < n; i++ {
		// Check if all three characters at index i are the same
		if a[i] == b[i] && b[i] == c[i] {
			// Do nothing, as no points are awarded for identical characters
		}
		// Check if any two characters are the same
		else if a[i] == b[i] || b[i] == c[i] || a[i] == c[i] {
			// Increment the answer by 1 for matching pairs
			ans++
		}
		// If all characters are different
		else {
			// Increment the answer by 2 for all different characters
			ans += 2
		}
	}

	// Output the final answer
	fmt.Println(ans)
}


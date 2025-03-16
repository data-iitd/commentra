package main

import (
	"fmt"
)

func main() {
	var h int64 // Initialize variable h to store input integer
	var ans, cnt int64 = 0, 1 // Initialize variables

	// Read input integer h from standard input
	fmt.Scan(&h)

	// Loop until h becomes 1
	for h != 1 {
		// If h is odd, decrement it by 1
		if h%2 != 0 {
			h--
		}

		// Divide h by 2 and multiply cnt by 2
		h /= 2
		cnt *= 2

		// Add the new value of cnt to the answer
		ans += cnt
	}

	// Output the final answer plus 1
	fmt.Println(ans + 1)
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	// Initialize variables to store the answer, count
	var ans, cnt int64 = 0, 1

	// Read the input value for h
	var h int64
	fmt.Scan(&h)

	// Loop until h becomes 1
	for h != 1 {
		// If h is odd, decrement it by 1 to make it even
		if h%2 != 0 {
			h--
		}

		// Divide h by 2
		h /= 2

		// Double the count for each iteration
		cnt *= 2

		// Accumulate the count into the answer
		ans += cnt
	}

	// Output the final answer incremented by 1
	fmt.Println(ans + 1)
}

// <END-OF-CODE>

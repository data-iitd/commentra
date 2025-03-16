package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize variables to store the answer, maximum value, sum, minimum value, and count
	ans, mx, sum, mn, cnt := 0, 0, 0, 1e8, 1

	// Read the input value for h
	var h int
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


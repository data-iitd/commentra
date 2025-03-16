package main

import (
	"fmt"
	"math"
)

func main() {
	var h int64 // Declare variable h to store input integer

	// Read input integer h from standard input
	fmt.Scan(&h)

	// Declare variables ans, mx, sum, mn, and cnt
	var ans, mx, sum, mn, cnt int64 = 1, 1, 0, 1e8, 1

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


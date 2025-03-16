package main

import (
	"fmt"
	"math"
)

func main() {
	var q int
	fmt.Scan(&q) // Read the number of queries

	for q > 0 {
		q--
		var n int
		fmt.Scan(&n) // Read the number n for the current query

		s := 0
		x := int(math.Log2(float64(n))) + 1 // Calculate the position of the most significant bit of n

		s = -1 * int(math.Pow(2, float64(x))) + 2 + (int(n) * (int(n) + 1)) / 2 - int(math.Pow(2, float64(x)))
		// Calculate s using arithmetic operations and power functions

		fmt.Println(s) // Print the result s for the current query
	}
}


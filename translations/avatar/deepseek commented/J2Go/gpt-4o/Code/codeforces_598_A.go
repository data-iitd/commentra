package main

import (
	"fmt"
	"math"
)

func main() {
	var q int
	fmt.Scan(&q) // Read the number of queries

	for q > 0 {
		q-- // Decrement the query count
		var n int
		fmt.Scan(&n) // Read the number n for the current query

		var s int64 = 0 // Initialize the sum variable s

		x := int(math.Log2(float64(n))) // Calculate the position of the most significant bit of n
		x++ // Increment x by 1

		s = -1*int64(math.Pow(2, float64(x))) + 2 + (int64(n)*int64(n+1))/2 - int64(math.Pow(2, float64(x)))
		// Calculate s using arithmetic operations and power functions

		fmt.Println(s) // Print the result s for the current query
	}
}

// <END-OF-CODE>

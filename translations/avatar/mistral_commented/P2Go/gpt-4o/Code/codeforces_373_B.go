package main

import (
	"fmt"
)

func sum(k int64) int64 {
	// Initialize the sum to zero
	ret := int64(0)
	// Base value for power of ten
	pw := int64(10)
	// Initialize the length of the number to 1
	length := int64(1)

	// Continue the loop until the power of ten is less than or equal to the number
	for {
		// Calculate the current digit
		cur := min(pw-1, k)
		// Calculate the previous power of ten
		prev := pw / 10
		// Add the number of digits in the current power of ten to the sum
		ret += (cur - prev + 1) * length
		// If the power of ten is greater than the number, break the loop
		if pw-1 >= k {
			break
		}
		// Increment the length of the number
		length++
		// Multiply the power of ten by 10
		pw *= 10
	}

	// Return the sum of digits in the number
	return ret
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Take input of w, m, and k
	var w, m, k int64
	fmt.Scan(&w, &m, &k)

	// Initialize the lower bound to 0
	lo := int64(0)
	// Initialize the upper bound to a very large number
	hi := int64(1e18)

	// Binary search to find the middle value
	for hi-lo > 1 {
		// Calculate the middle value
		md := (lo + hi) / 2
		// Calculate the sum of digits in the range [m, m+md] and subtract the sum of digits in the range [m-1, m]
		c := sum(m+md-1) - sum(m-1)
		// If the product of the count and k is less than or equal to w, update the lower bound
		if c*k <= w {
			lo = md
		} else {
			// Otherwise, update the upper bound
			hi = md
		}
	}

	// Print the result
	fmt.Println(lo)
}

// <END-OF-CODE>

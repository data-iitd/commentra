package main

import (
	"fmt"
	"math"
)

func main() {
	// Read input values for w, m, and k
	var w, m, k int
	fmt.Scanf("%d %d %d", &w, &m, &k)

	// Initialize the lower and upper bounds for binary search
	lo, hi := 0, int(math.Pow10(18))

	// Perform binary search to find the maximum value satisfying the condition
	for hi-lo > 1 {
		// Calculate the midpoint of the current bounds
		md := (lo + hi) / 2

		// Calculate the count of numbers in the range [m, m + md - 1]
		c := sum(m+md-1) - sum(m-1)

		// Check if the count multiplied by k is less than or equal to w
		if c*k <= w {
			// If true, adjust the lower bound to md
			lo = md
		} else {
			// Otherwise, adjust the upper bound to md
			hi = md
	}

	// Print the final result which is the maximum value found
	fmt.Println(lo)
}

// sum returns the count of numbers in the range [0, k]
func sum(k int) int {
	// Initialize the result variable to store the total count
	ret := 0
	// Initialize the power of ten to track the current range
	pw := 10
	// Initialize the length of the current digit
	length := 1

	// Loop indefinitely until a break condition is met
	for {
		// Calculate the current upper limit for the range
		cur := min(pw-1, k)
		// Calculate the previous lower limit for the range
		prev := pw / 10

		// Update the result with the count of numbers in the current range
		ret += (cur - prev + 1) * length

		// If the current upper limit exceeds k, exit the loop
		if pw-1 >= k {
			break
		}

		// Increase the length for the next range of digits
		length++
		// Move to the next power of ten
		pw *= 10

	}

	// Return the total count of numbers up to k
	return ret
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


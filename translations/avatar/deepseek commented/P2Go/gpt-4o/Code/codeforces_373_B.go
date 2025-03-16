package main

import (
	"fmt"
)

func sum(k int64) int64 {
	// Initialize the return value and other variables
	ret := int64(0)
	pw := int64(10)
	length := int64(1)

	// Loop to calculate the sum of digits from 1 to k
	for {
		// Calculate the current range of numbers
		cur := min(pw-1, k)
		prev := pw / 10

		// Add the count of numbers in the current range to the result
		ret += (cur - prev + 1) * length

		// Break the loop if the current range exceeds k
		if pw-1 >= k {
			break
		}

		// Update the length and power of ten for the next range
		length++
		pw *= 10
	}
	return ret
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Read input values for w, m, and k
	var w, m, k int64
	fmt.Scan(&w, &m, &k)

	// Initialize the binary search range
	lo := int64(0)
	hi := int64(1e18)

	// Perform binary search to find the maximum md
	for hi-lo > 1 {
		md := (lo + hi) / 2
		// Calculate the count of numbers in the range [m, m+md-1]
		c := sum(m + md - 1) - sum(m - 1)

		// Adjust the search range based on the condition
		if c*k <= w {
			lo = md
		} else {
			hi = md
		}
	}

	// Print the result of the binary search
	fmt.Println(lo)
}

// <END-OF-CODE>

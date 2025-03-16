
package main

import (
	"fmt"
	"math"
)

func sum(k int) int {
	// Initialize the return value and other variables
	ret := 0
	pw := 10
	len := 1
	// Loop to calculate the sum of digits from 1 to k
	for {
		// Calculate the current range of numbers
		cur := int(math.Min(float64(pw-1), float64(k)))
		prev := pw / 10
		// Add the count of numbers in the current range to the result
		ret += (cur - prev + 1) * len
		// Break the loop if the current range exceeds k
		if pw-1 >= k {
			break
		}
		// Update the length and power of ten for the next range
		len += 1
		pw *= 10
	}
	return ret
}

// Read input values for w, m, and k
func main() {
	var w, m, k int
	fmt.Scan(&w, &m, &k)

	// Initialize the binary search range
	lo := 0
	hi := int(math.Pow(10, 18))

	// Perform binary search to find the maximum md
	for hi-lo > 1 {
		md := (lo + hi) / 2
		// Calculate the count of numbers in the range [m, m+md-1]
		c := sum(m+md-1) - sum(m-1)
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


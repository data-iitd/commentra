package main

import (
	"fmt"
	"math"
)

func main() {
	var l, r int
	fmt.Scan(&l, &r)

	curr := r
	s := 0

	// Count the number of digits in the current value (r)
	for curr > 0 {
		s++
		curr /= 10
	}

	// Calculate the first power of ten greater than r
	first := int(math.Pow(10, float64(s)))

	// Calculate the second value as half of the first power of ten
	second := first / 2

	// Initialize the answer variable to store the maximum product found
	ans := -1

	// Iterate through the possible candidates: l, r, first, and second
	for _, i := range []int{l, r, first, second} {
		// Check if the candidate is within the range [l, r]
		if i >= l && i <= r {
			curr := i
			rev := ""

			// Create the reverse number by subtracting each digit from 9
			for _, k := range fmt.Sprint(curr) {
				rev += fmt.Sprint(9 - int(k-'0'))
			}

			// Update the answer with the maximum product of the current number and its reverse
			currRev := 0
			fmt.Sscanf(rev, "%d", &currRev)
			product := curr * currRev
			if product > ans {
				ans = product
			}
		}
	}

	// Print the maximum product found
	fmt.Println(ans)
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	// Ask the user for the number of elements in the sequence
	var n int
	fmt.Scan(&n)

	// Initialize the indices of the left and right pointers
	l := 1
	r := n

	// Binary search algorithm
	for l < r {
		// Calculate the middle index
		mid := l + (r-l)/2

		// Calculate the number of elements on the left side of the middle index
		idxcnt := mid * (mid + 1) / 2

		// If the number of elements on the left side is less than the target number,
		// move the left pointer to the right of the middle index
		if idxcnt < n {
			l = mid + 1
		} else {
			// Otherwise, the target number is either at the middle index or on the right side,
			// so move the right pointer to the left of the middle index
			r = mid
		}
	}

	// The target number is at the index l-1, so we need to subtract the number of elements
	// on the left side of index l-1 from the total number of elements to get the target number
	l--

	// Calculate the number of elements on the left side of index l
	idxcnt := l * (l + 1) / 2

	// Print the target number
	fmt.Println(n - idxcnt)
}

// <END-OF-CODE>

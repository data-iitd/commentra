package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	id := 0

	var l, r int
	fmt.Scan(&l, &r)

	for i := 1; i < n; i++ {
		var li, ri int
		fmt.Scan(&li, &ri)

		if li <= l && r <= ri {
			id = i // Update the index to the current interval
		} else if li < l || r < ri {
			id = n // Mark as overlapping by setting id to n
		}

		// Update the bounds of the union of intervals
		l = int(math.Min(float64(l), float64(li))) // Update the left bound
		r = int(math.Max(float64(r), float64(ri))) // Update the right bound
	}

	// Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
	if id == n {
		fmt.Println(-1)
	} else {
		fmt.Println(id + 1)
	}
}

// <END-OF-CODE>

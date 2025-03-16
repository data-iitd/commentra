package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize id variable to 0
	id := 0

	// Read left and right boundary values for the first test case
	var l, r int
	fmt.Scan(&l, &r)

	// Iterate through the remaining test cases
	for i := 1; i < n; i++ {
		// Read left and right boundary values for the current test case
		var li, ri int
		fmt.Scan(&li, &ri)

		// Check if the current test case overlaps with the previously defined boundary values
		if li <= l && r <= ri {
			// Update id variable to the index of the current test case
			id = i
		} else if li < l || r < ri {
			// If the current test case does not overlap, keep id as n
			id = n
		}

		// Update boundary values based on the current test case
		l = int(math.Min(float64(l), float64(li)))
		r = int(math.Max(float64(r), float64(ri)))
	}

	// Print the index of the test case that satisfies the condition, or -1 if no such test case exists
	if id == n {
		fmt.Println(-1)
	} else {
		fmt.Println(id + 1)
	}
}

// <END-OF-CODE>

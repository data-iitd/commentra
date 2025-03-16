package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize variables to track the best candidate interval
	id := 0
	var l, r int
	fmt.Scan(&l, &r)

	// Process each interval
	for i := 1; i < n; i++ {
		var li, ri int
		fmt.Scan(&li, &ri)

		// Check if the current interval completely covers the best candidate interval
		if li <= l && r <= ri {
			id = i
		} else if li < l || r < ri {
			id = n
		}

		// Update the boundaries of the best candidate interval
		l = int(math.Min(float64(l), float64(li)))
		r = int(math.Max(float64(r), float64(ri)))
	}

	// Output the result
	if id == n {
		fmt.Println(-1)
	} else {
		fmt.Println(id + 1)
	}
}

// <END-OF-CODE>

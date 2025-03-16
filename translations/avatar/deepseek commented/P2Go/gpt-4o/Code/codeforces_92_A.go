package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	// Taking two integer inputs, `n` and `m`

	i := 1
	// Initializing `i` to 1

	for m >= i {
		// The loop continues as long as `m` is greater than or equal to `i`
		m -= i
		// Subtracting `i` from `m`
		i = (i % n) + 1
		// Updating `i` to be `(i % n) + 1`
	}

	fmt.Println(m)
	// Printing the value of `m` after the loop completes
}

// <END-OF-CODE>

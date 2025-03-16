package main

import (
	"fmt"
)

func main() {
	var a, b int
	// Taking two integer inputs, `a` and `b`.
	fmt.Scan(&a, &b)

	hole := 1
	i := 0
	// Initializing `hole` to 1 and `i` to 0.
	check := true
	// Setting a boolean variable `check` to `true`.

	for check {
		// The `for` loop runs as long as `check` is `true`.
		if hole >= b {
			// Checking if `hole` is greater than or equal to `b`.
			check = false
			// If so, set `check` to `false` to exit the loop.
		} else {
			hole = a*(i+1) - i
			// If `hole` is less than `b`, update `hole` to `a * (i + 1) - i`.
			i++
			// Increment `i` by 1.
		}
	}
	fmt.Println(i)
	// Finally, print the value of `i` after the loop exits.
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	// Take an integer input `n`
	var n int
	fmt.Scan(&n)

	// Initialize `l` and `r` to 1 and `n` respectively
	l := 1
	r := n

	// The `while` loop runs as long as `l` is less than `r`
	for l < r {
		// Calculate the midpoint `mid`
		mid := l + (r-l)/2
		// Calculate the triangular number `idxcnt` at `mid`
		idxcnt := float64(mid * (mid + 1)) / 2
		// If `idxcnt` is less than `n`, update `l` to `mid + 1`
		if idxcnt < float64(n) {
			l = mid + 1
		} else {
			// Otherwise, update `r` to `mid`
			r = mid
		}
	}

	// Decrease `l` by 1 and calculate the triangular number `idxcnt` at `l`
	l--
	idxcnt := float64(l * (l + 1)) / 2

	// Print the difference between `n` and `idxcnt`
	fmt.Println(int(n - int(idxcnt)))
}

// <END-OF-CODE>

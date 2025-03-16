
package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Take an integer input `n`
	n, _ := strconv.Atoi(input())

	// Initialize `l` and `r` to 1 and `n` respectively
	l := 1
	r := n

	// The `for` loop runs as long as `l` is less than `r`
	for l < r {
		// Calculate the midpoint `mid`
		mid := l + (r-l)/2
		// Calculate the triangular number `idxcnt` at `mid`
		idxcnt := mid * (mid + 1) / 2
		// If `idxcnt` is less than `n`, update `l` to `mid + 1`
		if idxcnt < n {
			l = mid + 1
		} else {
			// Otherwise, update `r` to `mid`
			r = mid
		}
	}

	// Decrease `l` by 1 and calculate the triangular number `idxcnt` at `l`
	l--
	idxcnt := l * (l + 1) / 2

	// Print the difference between `n` and `idxcnt`
	fmt.Println(n - idxcnt)
}

// 
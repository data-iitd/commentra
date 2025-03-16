package main

import (
	"fmt"
	"math"
)

const (
	inf = 1e20
	mod = 1e9 + 7
)

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	// Reading four integers from standard input.

	result := max(max(a*c, b*d), max(a*d, b*c))
	// Calculating the maximum of four possible products of two of the given numbers.

	fmt.Println(result)
	// Printing the result.
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// <END-OF-CODE>

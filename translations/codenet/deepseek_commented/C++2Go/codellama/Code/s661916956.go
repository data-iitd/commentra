package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read three integers from the standard input
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	// Sort the integers in ascending order
	if a > b {
		a, b = b, a
	}
	if b > c {
		b, c = c, b
	}
	if a > b {
		a, b = b, a
	}

	// Print the sorted integers
	fmt.Println(a, b, c)
}


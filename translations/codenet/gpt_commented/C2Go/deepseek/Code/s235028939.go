package main

import (
	"fmt"
)

func main() {
	// Declare two integer variables n and m
	var n, m int

	// Read two integers from standard input
	// n represents the number of rows, and m represents the number of columns
	fmt.Scan(&n, &m)

	// Calculate the product of (n - 1) and (m - 1)
	// This represents the number of internal edges in a grid of n by m cells
	fmt.Println((n - 1) * (m - 1))
}


package main

import (
	"fmt"
)

func main() {
	// Create a scanner to read input
	var n int
	fmt.Scan(&n)

	// Initialize sums of subsets
	var a, b, c int

	// Sum all n elements
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		a += num
	}

	// Sum n-1 elements
	for i := 0; i < n-1; i++ {
		var num int
		fmt.Scan(&num)
		b += num
	}

	// Sum n-2 elements
	for i := 0; i < n-2; i++ {
		var num int
		fmt.Scan(&num)
		c += num
	}

	// Calculate the differences
	x := a - b
	y := b - c

	// Output the results
	fmt.Println(x)
	fmt.Println(y)
}

// <END-OF-CODE>

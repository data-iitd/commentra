package main

import (
	"fmt"
)

func main() {
	// Reading input
	var N int
	fmt.Scan(&N)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	// Calculating the XOR of all elements in the slice 'a'
	total := 0
	for _, ai := range a {
		total ^= ai
	}

	// Printing the result
	for _, ai := range a {
		fmt.Print(ai ^ total, " ")
	}
	fmt.Println()
}

// <END-OF-CODE>

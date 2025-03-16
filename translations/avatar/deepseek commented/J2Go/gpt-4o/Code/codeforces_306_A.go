package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a slice of size m
	a := make([]int, m)

	// Check if n is divisible by m
	if n%m == 0 {
		// Fill the slice with equal parts if n is divisible by m
		for i := 0; i < len(a); i++ {
			a[i] = n / m
		}
	} else {
		// Calculate the base part size
		sub := n / m

		// Fill the slice with the base part size
		for i := 0; i < len(a); i++ {
			a[i] = sub
		}

		// Distribute the remainder
		test := n - (sub * m)
		count := 0
		for i := 0; i < test; i++ {
			a[count]++
			count++
			if count >= len(a) {
				count = 0
			}
		}
	}

	// Print the slice elements in reverse order
	for i := len(a) - 1; i >= 0; i-- {
		fmt.Print(a[i], " ")
	}
}

// <END-OF-CODE>

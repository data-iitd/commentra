package main

import (
	"fmt"
)

func main() {
	// Read two integers n and m from user input
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a slice of size m to hold the results
	a := make([]int, m)

	// Check if n is divisible by m
	if n%m == 0 {
		// If divisible, fill the slice with equal parts
		for i := 0; i < len(a); i++ {
			a[i] = n / m
		}
	} else {
		// If not divisible, calculate the base value for each part
		sub := n / m
		for i := 0; i < len(a); i++ {
			a[i] = sub
		}

		// Calculate the remainder that needs to be distributed
		test := n - (sub * m)
		count := 0

		// Distribute the remainder across the first few elements of the slice
		for i := 0; i < test; i++ {
			a[count]++
			count++

			// Wrap around if count exceeds the slice length
			if count >= len(a) {
				count = 0
			}
		}
	}

	// Print the slice in reverse order
	for i := len(a) - 1; i >= 0; i-- {
		fmt.Print(a[i], " ")
	}
}

// <END-OF-CODE>

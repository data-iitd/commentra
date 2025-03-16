package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int

	// Read the number of elements in the array
	fmt.Scan(&n)

	// Declare a slice of size n
	a := make([]int, n)

	// Read n elements into the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize total sum variable
	t := 0

	// Outer loop to iterate through each element of the slice
	for i := 0; i < n; i++ {
		// Initialize sum for the current element
		s := 0

		// Inner loop to calculate the product of the current element with all subsequent elements
		for j := 1; j < n; j++ {
			// Skip elements that are not after the current element
			if j <= i {
				continue
			}

			// Calculate the product of the current element a[i] and a[j]
			m := a[i] * a[j]

			// Add the product to the sum for the current element
			s += m
		}

		// Add the sum of products for the current element to the total
		t += s
	}

	// Print the total sum of products
	fmt.Println(t)
}

// <END-OF-CODE>

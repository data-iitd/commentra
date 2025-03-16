package main

import (
	"fmt"
)

func main() {
	var n int
	// Read the size of the array
	fmt.Scan(&n)
	// Declare a slice of size n
	a := make([]int, n)
	// Read n integers and store them in the slice a
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	// Initialize t to 0, which will store the final sum of products
	t := 0
	// Outer loop to iterate over each element in the slice a
	for i := 0; i < n; i++ {
		// Initialize s to 0, which will store the sum of products for the current element
		s := 0
		// Inner loop to iterate over each element in the slice a, skipping the current element
		for j := 0; j < n; j++ {
			if j <= i {
				continue // Skip the current element being processed by the outer loop
			}
			// Calculate the product of the current element and the current element in the inner loop
			m := a[i] * a[j]
			// Add the product to the sum s
			s += m
		}
		// Add the sum s to the final sum t
		t += s
	}
	// Print the final sum of products
	fmt.Println(t)
}

// <END-OF-CODE>

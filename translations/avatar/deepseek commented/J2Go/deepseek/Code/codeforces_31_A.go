package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements in the array

	a := make([]int, n) // Array to store the elements

	// Read the elements of the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	f := 0 // Flag to indicate if the triplet is found

	// Outer loop to iterate over each element as a potential a[k]
	for k := 0; k < n; k++ {
		t := a[k] // Current element as t

		// Inner loops to find two indices i and j such that a[i] + a[j] = t
		for i := 0; i < n; i++ {
			for j := 0; j < n-1; j++ {
				if i != j && t == (a[i]+a[j]) {
					f = 1 // Set flag to 1 if triplet is found
					break // Break out of the inner loop
				}
			}
			if f == 1 {
				break // Break out of the outer loop if triplet is found
			}
		}
		if f == 1 {
			break // Break out of the main loop if triplet is found
		}
	}

	// Check if a triplet was found and print the result
	if f == 1 {
		fmt.Println(k+1, j+1, i+1)
	} else {
		fmt.Println(-1)
	}
}


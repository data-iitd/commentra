package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements from standard input
	var n int
	fmt.Scan(&n)

	// Initialize a slice to hold the float64 numbers
	a := make([]float64, n)

	// Read n float64 numbers from standard input into the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Perform a series of operations to reduce the slice
	for i := 0; i+1 < n; i++ {
		// Sort the slice in ascending order
		sort.Sort(sort.Float64Slice(a))

		// Create a new slice to hold the modified values
		na := make([]float64, 0)

		// Append all elements from the third element onward to the new slice
		for j := 2; j < len(a); j++ {
			na = append(na, a[j])
		}

		// Calculate the average of the first two elements and append it to the new slice
		na = append(na, (a[0]+a[1])/2)

		// Update the original slice to be the new slice
		a = na
	}

	// Print the final remaining element in the slice
	fmt.Println(a[0])
}

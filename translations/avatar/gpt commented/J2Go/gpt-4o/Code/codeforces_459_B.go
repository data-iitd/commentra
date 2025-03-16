package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements from input
	var N int
	fmt.Scan(&N)

	// Initialize a slice to hold the input integers
	A := make([]int, N)

	// Read N integers from input and store them in the slice A
	for n := 0; n < N; n++ {
		fmt.Scan(&A[n])
	}

	// Sort the slice A to easily find the minimum and maximum values
	sort.Ints(A)

	// Identify the minimum and maximum values in the sorted slice
	min := A[0]
	max := A[N-1]

	// Initialize counters for occurrences of min and max values
	mins, maxs := 0, 0

	// Count how many times the minimum and maximum values occur in the slice
	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}

	// If all elements are the same (min equals max)
	if min == max {
		// Calculate the difference (which is 0) and the number of ways to choose 2 from mins
		fmt.Println((max - min), mins*(mins-1)/2)
	} else {
		// Calculate the difference and the product of occurrences of min and max
		fmt.Println((max - min), mins*maxs)
	}
}

// <END-OF-CODE>

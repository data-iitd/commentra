package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements N from the standard input.
	X := make([]int, N) // Declare a slice X of size N to store the elements.
	Y := make([]int, N) // Declare a slice Y of size N to store the elements.

	// Read N elements into slice X and simultaneously copy them to slice Y.
	for i := 0; i < N; i++ {
		fmt.Scan(&X[i])
		Y[i] = X[i]
	}

	// Sort the slice Y in ascending order.
	sort.Ints(Y)

	// Calculate the median of the sorted slice Y.
	var y int
	if N%2 == 0 {
		y = (Y[N/2-1] + Y[N/2]) / 2 // Average of the two middle elements for even N.
	} else {
		y = Y[N/2] // The middle element for odd N.
	}

	// Iterate through each element in slice X and output the appropriate median value based on the comparison with y.
	for i := 0; i < N; i++ {
		if X[i] < y {
			fmt.Println(y) // If the element in X is less than the median, output the median.
		} else {
			fmt.Println(y - 1) // Otherwise, output the median minus one.
		}
	}
}

// <END-OF-CODE>

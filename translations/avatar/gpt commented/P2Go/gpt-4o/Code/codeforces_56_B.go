package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements in the list
	var N int
	fmt.Scan(&N)

	// Read the list of integers from input
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize minimum and maximum indices for the range of elements that are out of place
	mn, mx := N+1, -1

	// Iterate through the list to find the first and last indices where the element is not in its correct position
	for i := 0; i < N; i++ {
		// Check if the current index + 1 does not match the value at that index
		if (i+1 != A[i]) {
			// Update the minimum index if the current index is less than the current minimum
			if i < mn {
				mn = i
			}
			// Update the maximum index if the current index is greater than the current maximum
			if i > mx {
				mx = i
			}
		}
	}

	// If no elements were out of place, output '0 0'
	if mx == -1 {
		fmt.Println("0 0")
	} else {
		// Reverse the subarray from mn to mx
		reversed := make([]int, mx-mn+1)
		for i := 0; i <= mx-mn; i++ {
			reversed[i] = A[mx-i]
		}
		// Concatenate it with the rest of the list
		A = append(A[:mn], append(reversed, A[mx+1:]...)...)

		// Check if the modified list is sorted
		if sort.IntsAreSorted(A) {
			// If sorted, print the 1-based indices of the range that was reversed
			fmt.Println(mn+1, mx+1)
		} else {
			// If not sorted, output '0 0'
			fmt.Println("0 0")
		}
	}
}

// <END-OF-CODE>

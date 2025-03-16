package main

import (
	"fmt"
)

func main() {
	// Read input: number of elements 'n' and the difference 'k'
	var n, k int
	fmt.Scan(&n, &k)

	// Read input: list of elements 'elems'
	elems := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&elems[i])
	}

	// Helper function to check if all elements in a slice are the same
	allSame := func(arr []int) bool {
		for _, x := range arr {
			if x != arr[0] {
				return false
			}
		}
		return true
	}

	// Check if all elements in the slice are the same
	if allSame(elems) {
		// If all elements are the same, print 0 and exit
		fmt.Println(0)
		return
	}

	// Check if difference 'k' is 1
	if k == 1 {
		// If difference is 1, print -1 and exit
		fmt.Println(-1)
		return
	}

	// Check if last 'k' elements in the slice are not all the same
	if !allSame(elems[n-k:]) {
		// If last 'k' elements are not the same, print -1 and exit
		fmt.Println(-1)
		return
	}

	// Initialize target element
	target := elems[n-1]

	// Initialize slice 'toDelete' to store elements to be deleted
	toDelete := elems[:k-1]

	// While 'toDelete' is not empty and its last element is 'target'
	for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
		// Remove the last element from 'toDelete'
		toDelete = toDelete[:len(toDelete)-1]
	}

	// Print the length of 'toDelete'
	fmt.Println(len(toDelete))
}

// <END-OF-CODE>

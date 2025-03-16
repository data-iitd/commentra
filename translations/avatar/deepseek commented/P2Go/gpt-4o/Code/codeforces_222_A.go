package main

import (
	"fmt"
)

func allSame(arr []int) bool {
	for _, x := range arr {
		if x != arr[0] {
			return false
		}
	}
	return true
}

func main() {
	// Read the number of elements (n) and the parameter (k)
	var n, k int
	fmt.Scan(&n, &k)

	// Read the list of elements
	elems := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&elems[i])
	}

	// Check if all elements in the list are the same
	if allSame(elems) {
		// If all elements are the same, print 0 and return
		fmt.Println(0)
		return
	}

	// If k is 1, print -1 and return
	if k == 1 {
		fmt.Println(-1)
		return
	}

	// Check if elements from index k-1 to the end are all the same
	if !allSame(elems[k-1:]) {
		// If not, print -1 and return
		fmt.Println(-1)
		return
	}

	// Set the target to the last element of the list
	target := elems[n-1]

	// Initialize to_delete as elements from the start to k-1
	toDelete := elems[:k-1]

	// Remove elements from toDelete that are equal to target until a different element is found
	for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
		toDelete = toDelete[:len(toDelete)-1]
	}

	// Print the length of toDelete
	fmt.Println(len(toDelete))
}

// <END-OF-CODE>

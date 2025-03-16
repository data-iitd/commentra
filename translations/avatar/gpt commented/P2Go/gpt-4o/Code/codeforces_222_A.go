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
	// Read two integers n and k from input
	var n, k int
	fmt.Scan(&n, &k)

	// Read a list of n integers from input
	elems := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&elems[i])
	}

	// If all elements in elems are the same, print 0 and exit
	if allSame(elems) {
		fmt.Println(0)
		return
	}

	// If k is 1, it's impossible to satisfy the conditions, print -1 and exit
	if k == 1 {
		fmt.Println(-1)
		return
	}

	// If the last k-1 elements are not the same, print -1 and exit
	if !allSame(elems[k-1:]) {
		fmt.Println(-1)
		return
	}

	// Set the target value to the last element of elems
	target := elems[n-1]

	// Create a slice of elements to delete, which are the first k-1 elements
	toDelete := elems[:k-1]

	// Remove elements from toDelete that are equal to the target from the end
	for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
		toDelete = toDelete[:len(toDelete)-1]
	}

	// Print the number of elements that need to be deleted
	fmt.Println(len(toDelete))
}

// <END-OF-CODE>

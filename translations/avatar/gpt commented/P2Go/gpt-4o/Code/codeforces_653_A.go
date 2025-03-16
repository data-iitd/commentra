package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read an integer input which represents the number of elements in the list
	var n int
	fmt.Scan(&n)

	// Read a line of input, split it into individual string elements, convert them to integers, and store them in a slice
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Sort the slice in ascending order
	sort.Ints(l)

	// Iterate through each element in the sorted slice
	for _, i := range l {
		// Check if both i + 1 and i + 2 exist in the slice
		if contains(l, i+1) && contains(l, i+2) {
			// If the condition is met, print 'YES' and exit the loop
			fmt.Println("YES")
			return
		}
	}
	// If the loop completes without finding the condition, print 'NO'
	fmt.Println("NO")
}

// Helper function to check if a slice contains a specific value
func contains(slice []int, value int) bool {
	for _, v := range slice {
		if v == value {
			return true
		}
	}
	return false
}

// <END-OF-CODE>

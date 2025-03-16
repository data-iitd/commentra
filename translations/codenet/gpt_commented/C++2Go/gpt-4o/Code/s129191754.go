package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the elements and read them from input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Sort the slice to facilitate duplicate checking
	sort.Ints(a)

	// Check for duplicates in the sorted slice
	for i := 0; i < n-1; i++ {
		if a[i] == a[i+1] {
			// If a duplicate is found, print "NO" and exit
			fmt.Println("NO")
			return
		}
	}

	// If no duplicates are found, print "YES"
	fmt.Println("YES")
}

// <END-OF-CODE>

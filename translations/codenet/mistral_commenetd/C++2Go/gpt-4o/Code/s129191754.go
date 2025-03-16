package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize a slice of size n
	a := make([]int, n)

	// Read the elements of the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Sort the slice in ascending order
	sort.Ints(a)

	// Check if there are any consecutive elements in the sorted slice
	for i := 0; i < n-1; i++ {
		// If there are consecutive elements, print "NO" and exit the program
		if a[i] == a[i+1] {
			fmt.Println("NO")
			return
		}
	}

	// If no consecutive elements were found, print "YES"
	fmt.Println("YES")
}

// <END-OF-CODE>

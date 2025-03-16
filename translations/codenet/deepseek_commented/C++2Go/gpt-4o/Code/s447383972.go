package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the size of the array.
	a := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the elements of the array.
	}

	sort.Ints(a) // Sort the array.

	// Remove duplicates from the array.
	q := []int{}
	for i := 0; i < n; i++ {
		if i == 0 || a[i] != a[i-1] {
			q = append(q, a[i])
		}
	}

	// Print the product of the two largest distinct elements.
	if len(q) >= 2 {
		fmt.Println(q[len(q)-1] * q[len(q)-2])
	} else {
		fmt.Println(0) // Handle case where there are less than 2 distinct elements.
	}
}

// <END-OF-CODE>

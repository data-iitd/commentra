package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	p := make([]int, n)

	// Read n integers and store them in the array p
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}

	// Perform selection sort on the array p
	for i := 0; i < n; i++ {
		l := i
		for j := i + 1; j < n; j++ {
			if p[j] < p[l] {
				l = j
			}
		}
		if l != i {
			p[i], p[l] = p[l], p[i] // Swap elements
		}
	}

	// Sum the first k elements of the sorted array
	o := 0
	for i := 0; i < k; i++ {
		o += p[i]
	}

	// Print the sum of the first k elements
	fmt.Println(o)
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"sort"
)

func main() {
	var x, y, z, k int
	fmt.Scan(&x, &y, &z, &k)
	// Taking four integer inputs: x, y, z, and k

	a := make([]int, x)
	for i := 0; i < x; i++ {
		fmt.Scan(&a[i])
	}
	// Reading list a of integers

	b := make([]int, y)
	for i := 0; i < y; i++ {
		fmt.Scan(&b[i])
	}
	// Reading list b of integers

	c := make([]int, z)
	for i := 0; i < z; i++ {
		fmt.Scan(&c[i])
	}
	// Reading list c of integers

	ab := []int{}
	// Initializing an empty slice ab to store sums of elements from a and b

	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i]+b[j])
		}
	}
	// Populating slice ab with sums of elements from a and b

	sort.Sort(sort.Reverse(sort.IntSlice(ab)))
	// Sorting slice ab in descending order

	abc := []int{}
	// Initializing an empty slice abc to store sums of elements from ab and c

	for i := 0; i < min(k, x*y); i++ {
		for j := 0; j < z; j++ {
			abc = append(abc, ab[i]+c[j])
		}
	}
	// Populating slice abc with sums of elements from ab and c, limited by k

	sort.Sort(sort.Reverse(sort.IntSlice(abc)))
	// Sorting slice abc in descending order

	for i := 0; i < k; i++ {
		fmt.Println(abc[i])
	}
	// Printing the first k elements of abc in descending order
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>

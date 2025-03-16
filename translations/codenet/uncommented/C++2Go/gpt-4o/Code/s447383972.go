package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	sort.Ints(a)

	var q []int
	for i := 0; i < n; i++ {
		if i < n-1 && a[i] == a[i+1] {
			q = append(q, a[i])
			i++ // Skip the next element since it's the same
		}
	}

	if len(q) >= 2 {
		fmt.Println(q[len(q)-1] * q[len(q)-2])
	} else {
		fmt.Println(0) // Handle case where there are not enough duplicates
	}
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"sort"
)

func main() {
	var x, y, z, k int
	fmt.Scan(&x, &y, &z, &k)

	a := make([]int, x)
	for i := 0; i < x; i++ {
		fmt.Scan(&a[i])
	}

	b := make([]int, y)
	for i := 0; i < y; i++ {
		fmt.Scan(&b[i])
	}

	c := make([]int, z)
	for i := 0; i < z; i++ {
		fmt.Scan(&c[i])
	}

	ab := []int{}
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i]+b[j])
		}
	}
	sort.Sort(sort.Reverse(sort.IntSlice(ab)))

	abc := []int{}
	for i := 0; i < min(k, len(ab)); i++ {
		for j := 0; j < z; j++ {
			abc = append(abc, ab[i]+c[j])
		}
	}
	sort.Sort(sort.Reverse(sort.IntSlice(abc)))

	for i := 0; i < k; i++ {
		fmt.Println(abc[i])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>

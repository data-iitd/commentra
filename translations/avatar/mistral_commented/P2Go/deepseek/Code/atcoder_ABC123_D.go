package main

import (
	"fmt"
	"sort"
)

func main() {
	var x, y, z, k int
	fmt.Scan(&x, &y, &z, &k)

	a := make([]int, x*y)
	b := make([]int, y*z)
	c := make([]int, z)

	for i := 0; i < x*y; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < y*z; i++ {
		fmt.Scan(&b[i])
	}
	for i := 0; i < z; i++ {
		fmt.Scan(&c[i])
	}

	ab := make([]int, 0, x*y)
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i*y+j]+b[i*y+j])
		}
	}

	sort.Slice(ab, func(i, j int) bool {
		return ab[i] > ab[j]
	})

	abc := make([]int, 0, min(k, len(ab)*z))
	for i := 0; i < min(k, len(ab)); i++ {
		for j := 0; j < z; j++ {
			abc = append(abc, ab[i]+c[j])
		}
	}

	sort.Slice(abc, func(i, j int) bool {
		return abc[i] > abc[j]
	})

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


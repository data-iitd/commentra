package main

import (
	"fmt"
	"sort"
)

func main() {
	var x, y, z, k int
	fmt.Scan(&x, &y, &z, &k)

	var a, b, c []int
	for i := 0; i < x; i++ {
		var ai int
		fmt.Scan(&ai)
		a = append(a, ai)
	}
	for i := 0; i < y; i++ {
		var bi int
		fmt.Scan(&bi)
		b = append(b, bi)
	}
	for i := 0; i < z; i++ {
		var ci int
		fmt.Scan(&ci)
		c = append(c, ci)
	}

	ab := []int{}
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			ab = append(ab, a[i]+b[j])
		}
	}
	sort.Slice(ab, func(i, j int) bool {
		return ab[i] > ab[j]
	})

	abc := []int{}
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

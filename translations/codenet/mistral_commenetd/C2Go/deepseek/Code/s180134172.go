package main

import (
	"fmt"
)

func main() {
	var n, k int
	var p [99999]int

	fmt.Scan(&n, &k)

	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}

	for i := 0; i < n; i++ {
		l := i
		for j := i + 1; j < n; j++ {
			if p[j] < p[l] {
				l = j
			}
		}
		if l != i {
			p[i], p[l] = p[l], p[i]
		}
	}

	var o int
	for i := 0; i < k; i++ {
		o += p[i]
	}

	fmt.Println(o)
}


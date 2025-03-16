package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	p := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}

	// Selection sort
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

	o := 0
	for i := 0; i < k; i++ {
		o += p[i]
	}
	fmt.Println(o)
}

// <END-OF-CODE>

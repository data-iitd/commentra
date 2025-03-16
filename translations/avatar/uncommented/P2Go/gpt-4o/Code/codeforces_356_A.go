package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	out := make([]int, n)
	comp := make([]int, n)
	for i := 0; i < n; i++ {
		comp[i] = i + 2
	}

	for i := 0; i < m; i++ {
		var l, r, x int
		fmt.Scan(&l, &r, &x)
		t := l
		for t <= r {
			nextVal := comp[t-1]
			if out[t-1] == 0 && t != x {
				out[t-1] = x
			}
			if t >= x {
				comp[t-1] = r + 1
			} else {
				comp[t-1] = x
			}
			t = nextVal
		}
	}

	for _, val := range out {
		fmt.Print(val, " ")
	}
	fmt.Println()
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	var n, a, m, M, c, b, i int64
	c = 0
	M = -100000000
	m = 100000000

	fmt.Scan(&n)

	for i = 1; i <= n; i++ {
		fmt.Scan(&a)

		if a > M {
			M = a
		}

		if a < m {
			m = a
		}

		c += a
	}

	fmt.Printf("%d %d %d\n", m, M, c)
}


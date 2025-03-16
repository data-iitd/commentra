package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, a, m, M, c, b, i int64
	c = 0
	m = 100000000
	M = -100000000
	fmt.Scanf("%d", &n)

	for i = 1; i <= n; i++ {
		fmt.Scanf("%d", &a)
		if a > M {
			M = a
		}
		if a < m {
			m = a
		}
		c = c + a
	}
	fmt.Printf("%d %d %d\n", m, M, c)
}


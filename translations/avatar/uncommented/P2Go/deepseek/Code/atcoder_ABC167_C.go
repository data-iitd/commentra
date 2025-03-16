package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m, x int
	fmt.Scan(&n, &m, &x)

	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, m+1)
		for j := 0; j < m+1; j++ {
			fmt.Scan(&c[i][j])
		}
	}

	ans := -1
	for bit := 1; bit < (1 << n); bit++ {
		understand := make([]int, m+1)
		cost := 0
		for i := 0; i < n; i++ {
			if bit&(1<<i) != 0 {
				cost += c[i][0]
				for j := 1; j <= m; j++ {
					understand[j] += c[i][j]
				}
			}
		}
		ok := true
		for j := 1; j <= m; j++ {
			if understand[j] < x {
				ok = false
				break
			}
		}
		if ok {
			if ans == -1 || cost < ans {
				ans = cost
			}
		}
	}

	fmt.Println(ans)
}


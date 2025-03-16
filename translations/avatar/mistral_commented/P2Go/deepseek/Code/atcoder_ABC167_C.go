package main

import (
	"fmt"
	"math/bits"
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

	l := [][]int{}
	rem := []int{}
	var ans int

	for i := 0; i <= n; i++ {
		for j := 0; j < i; j++ {
			comb := []int{}
			for k := 0; k < n; k++ {
				if (j>>k)&1 == 1 {
					comb = append(comb, k)
				}
			}
			l = append(l, comb)
		}
	}

	for i := 1; i <= m; i++ {
		ca := 0
		for _, j := range l[i] {
			ca += c[j][i]
		}
		if ca < x {
			rem = append([]int{i}, rem...)
		}
	}

	for len(rem) > 0 {
		for _, j := range rem {
			l = append(l[:j], l[j+1:]...)
		}
		rem = []int{}
	}

	if len(l) == 0 {
		fmt.Println(-1)
		return
	}

	for _, i := range l {
		ca := 0
		for _, j := range i {
			ca += c[j][0]
		}
		if ans == 0 {
			ans = ca
		} else {
			ans = min(ans, ca)
		}
	}

	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


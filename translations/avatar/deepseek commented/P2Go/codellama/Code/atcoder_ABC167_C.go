package main

import (
	"fmt"
	"math"
	"sort"
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

	pre := make([]int, n)
	for i := 0; i < n; i++ {
		pre[i] = i
	}

	l := make([][]int, 0)
	rem := make([]int, 0)

	ans := 0
	for i := 1; i < m+1; i++ {
		for j := 0; j < len(pre)+1; j++ {
			for k, _ := range pre {
				ca := 0
				for ii := 0; ii < j; ii++ {
					ca += c[pre[ii]][i]
				}
				if ca < x {
					rem = append(rem, k)
				}
			}
			if len(rem) > 0 {
				for _, k := range rem {
					pre = append(pre[:k], pre[k+1:]...)
				}
				rem = rem[:0]
			}
			if len(pre) == 0 {
				fmt.Println(-1)
				return
			}
			for _, k := range pre {
				ca := 0
				for ii := 0; ii < j; ii++ {
					ca += c[k][0]
				}
				if ans == 0 {
					ans = ca
				} else {
					ans = int(math.Min(float64(ans), float64(ca)))
				}
			}
		}
	}
	fmt.Println(ans)
}


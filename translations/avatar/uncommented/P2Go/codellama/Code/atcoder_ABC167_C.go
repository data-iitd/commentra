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
	for i := range c {
		c[i] = make([]int, m+1)
		for j := range c[i] {
			fmt.Scan(&c[i][j])
		}
	}
	pre := make([]int, n)
	for i := range pre {
		pre[i] = i
	}
	l := make([][]int, 0)
	rem := make([]int, 0)
	ans := 0
	for i := 0; i < n; i++ {
		for j := 0; j < int(math.Pow(2, float64(n-i))); j++ {
			l = append(l, make([]int, 0))
			for k := 0; k < n; k++ {
				if j&(1<<k) != 0 {
					l[len(l)-1] = append(l[len(l)-1], k)
				}
			}
		}
	}
	for i := 1; i < m+1; i++ {
		for j, k := range l {
			ca := 0
			for _, ii := range k {
				ca += c[ii][i]
			}
			if ca < x {
				rem = append(rem, j)
			}
		}
		if len(rem) > 0 {
			for _, j := range rem {
				l = append(l[:j], l[j+1:]...)
			}
			rem = make([]int, 0)
		}
		if len(l) == 0 {
			fmt.Println(-1)
			return
		}
	}
	for _, i := range l {
		ca := 0
		for _, j := range i {
			ca += c[j][0]
		}
		if ans == 0 {
			ans = ca
		} else {
			ans = int(math.Min(float64(ans), float64(ca)))
		}
	}
	fmt.Println(ans)
}


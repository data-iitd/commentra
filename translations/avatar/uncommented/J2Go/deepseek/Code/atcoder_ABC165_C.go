package main

import (
	"fmt"
	"math"
)

var (
	a, b, c, d []int
	n, m, q   int
	ans       = -100
)

func main() {
	fmt.Scan(&n, &m, &q)
	a, b, c, d = make([]int, q), make([]int, q), make([]int, q), make([]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i], &b[i], &c[i], &d[i])
		a[i]--
		b[i]--
	}
	dfs(nil)
	fmt.Println(ans)
}

func dfs(list []int) {
	if len(list) == n {
		score := 0
		for i := 0; i < q; i++ {
			if list[b[i]]-list[a[i]] == c[i] {
				score += d[i]
			}
		}
		ans = int(math.Max(float64(ans), float64(score)))
		return
	}
	if len(list) > 0 {
		for num := list[len(list)-1]; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	} else {
		for num := 1; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	}
}


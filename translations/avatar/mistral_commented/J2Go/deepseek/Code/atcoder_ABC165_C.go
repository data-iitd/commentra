package main

import (
	"fmt"
)

var a, b, c, d []int
var n, m, q int
var ans int64 = -100

func main() {
	fmt.Scan(&n, &m, &q)

	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)

	for i := 0; i < q; i++ {
		fmt.Scan(&a[i], &b[i], &c[i], &d[i])
		a[i]--
		b[i]--
	}

	dfs(make([]int, 0))

	fmt.Println(ans)
}

func dfs(list []int) {
	if len(list) == n {
		var score int64 = 0

		for i := 0; i < q; i++ {
			if list[b[i]]-list[a[i]] == c[i] {
				score += int64(d[i])
			}
		}

		if score > ans {
			ans = score
		}
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


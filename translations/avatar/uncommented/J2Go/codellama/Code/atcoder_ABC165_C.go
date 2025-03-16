
package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m, q int
	fmt.Scan(&n, &m, &q)
	a := make([]int, q)
	b := make([]int, q)
	c := make([]int, q)
	d := make([]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i], &b[i], &c[i], &d[i])
	}
	ans := -100
	dfs([]int{}, 0)
	fmt.Println(ans)
}

func dfs(list []int, index int) {
	if index == n {
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
			dfs(list, index+1)
			list = list[:len(list)-1]
		}
	} else {
		for num := 1; num <= m; num++ {
			list = append(list, num)
			dfs(list, index+1)
			list = list[:len(list)-1]
		}
	}
}


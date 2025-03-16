
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		g[a-1] = append(g[a-1], i)
		g[b-1] = append(g[b-1], i)
	}

	ans := make([]int, n-1)
	dfs(0, -1, -1, g, ans)

	max := 0
	for _, temp := range ans {
		if temp > max {
			max = temp
		}
	}

	fmt.Println(max)
	for _, c := range ans {
		fmt.Println(c)
	}
}

func dfs(to, color, parents int, g [][]int, ans []int) {
	k := 1
	for _, e := range g[to] {
		if e == parents {
			continue
		}
		if k == color {
			k++
		}
		ans[e] = k
		dfs(e, k, to, g, ans)
		k++
	}
}


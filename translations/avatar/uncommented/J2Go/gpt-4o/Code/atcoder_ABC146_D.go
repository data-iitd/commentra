package main

import (
	"fmt"
)

type Edge struct {
	id  int
	to  int
}

var n int
var g [][]Edge
var ans []int

func main() {
	var n int
	fmt.Scan(&n)
	g = make([][]Edge, n)

	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to 0-based index
		b-- // Convert to 0-based index
		g[a] = append(g[a], Edge{id: i, to: b})
		g[b] = append(g[b], Edge{id: i, to: a})
	}

	ans = make([]int, n-1)
	dfs(0, -1, -1)

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

func dfs(to, color, parents int) {
	k := 1
	for _, e := range g[to] {
		if e.to == parents {
			continue
		}
		if k == color {
			k++
		}
		ans[e.id] = k
		dfs(e.to, k, to)
		k++
	}
}

// <END-OF-CODE>

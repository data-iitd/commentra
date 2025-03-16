
package main

import (
	"fmt"
	"math"
)

var n int
var g [][]Edge
var ans []int

func main() {
	var n int
	fmt.Scan(&n)
	g = make([][]Edge, n)
	for i := 0; i < n; i++ {
		g[i] = make([]Edge, 0)
	}
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		g[a-1] = append(g[a-1], Edge{i, b - 1})
		g[b-1] = append(g[b-1], Edge{i, a - 1})
	}
	ans = make([]int, n-1)
	dfs(0, -1, -1)
	max := 0
	for _, temp := range ans {
		max = int(math.Max(float64(max), float64(temp)))
	}
	fmt.Println(max)
	for _, c := range ans {
		fmt.Println(c)
	}
}

func dfs(to, color, parents int) {
	k := 1
	for _, e := range g[to] {
		if e.To == parents {
			continue
		}
		if k == color {
			k++
		}
		ans[e.Id] = k
		dfs(e.To, k, to)
		k++
	}
}

type Edge struct {
	Id  int
	To  int
}


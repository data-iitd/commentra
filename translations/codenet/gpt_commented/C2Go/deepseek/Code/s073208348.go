package main

import (
	"fmt"
	"sort"
)

type Edge struct {
	s, g, c int
}

type Graph struct {
	vcnt, ecnt int
	e          []Edge
	id         []int
}

var g Graph

func edgeSort(a, b interface{}) int {
	pa := a.(Edge)
	pb := b.(Edge)
	if pa.s < pb.s {
		return -1
	}
	if pa.s > pb.s {
		return 1
	}
	if pa.g < pb.g {
		return -1
	}
	return 1
}

func readGraph() {
	var n int
	fmt.Scan(&n)
	g.e = make([]Edge, 2*n-2)
	g.id = make([]int, n+1)
	for i := 0; i < n-1; i++ {
		var x, y, c int
		fmt.Scan(&x, &y, &c)
		g.e[2*i] = Edge{x, y, c}
		g.e[2*i+1] = Edge{y, x, c}
	}
	g.vcnt = n
	g.ecnt = 2*n - 2
	sort.Slice(g.e, func(i, j int) bool {
		return edgeSort(g.e[i], g.e[j]) < 0
	})
	p := 0
	for i := 0; i < g.vcnt; i++ {
		for p < g.ecnt && g.e[p].s < i {
			p++
		}
		g.id[i] = p
	}
	g.id[g.vcnt] = g.ecnt
}

var temp []int

func dfs(s int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if temp[g.e[i].g] == 0 {
			temp[g.e[i].g] = temp[s] + g.e[i].c
			dfs(g.e[i].g)
		}
	}
}

func diameter() int {
	temp = make([]int, g.vcnt+10)
	temp[0] = 1
	dfs(0)
	M, Mi := 0, 0
	for i := 0; i < g.vcnt; i++ {
		if temp[i] > M {
			M = temp[i]
			Mi = i
		}
	}
	for i := 0; i < g.vcnt; i++ {
		temp[i] = 0
	}
	temp[Mi] = 1
	dfs(Mi)
	for i := 0; i < g.vcnt; i++ {
		if temp[i] > M {
			M = temp[i]
		}
	}
	return M - 1
}

func main() {
	readGraph()
	fmt.Println(diameter())
}


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

func readGraph() {
	var n int
	fmt.Scan(&n)
	g.vcnt = n
	g.ecnt = 2*n - 2
	g.e = make([]Edge, g.ecnt)
	g.id = make([]int, n+1)
	for i := 0; i < n-1; i++ {
		var x, y, c int
		fmt.Scan(&x, &y, &c)
		g.e[i] = Edge{x, y, c}
		g.e[i+g.ecnt] = Edge{y, x, c}
	}
	g.ecnt *= 2
	sort.Slice(g.e, func(i, j int) bool {
		if g.e[i].s < g.e[j].s {
			return true
		}
		if g.e[i].s > g.e[j].s {
			return false
		}
		return g.e[i].g < g.e[j].g
	})
	p := 0
	for i := 0; i < n; i++ {
		for p < g.ecnt && g.e[p].s < i {
			p++
		}
		g.id[i] = p
	}
	g.id[n] = g.ecnt
}

var tyokkeitemp []int

func tyokkeiDFS(s int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if tyokkeitemp[g.e[i].g] == 0 {
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
			tyokkeiDFS(g.e[i].g)
		}
	}
}

func tyokkei() int {
	tyokkeitemp = make([]int, g.vcnt+10)
	tyokkeitemp[0] = 1
	tyokkeiDFS(0)
	M := 0
	Mi := 0
	for i := 0; i < g.vcnt; i++ {
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
			Mi = i
		}
	}
	free(tyokkeitemp)
	return M - 1
}

func main() {
	readGraph()
	fmt.Println(tyokkei())
}


package main

import (
	"fmt"
	"sort"
)

type Edge struct {
	s, g, c int64
}

type Graph struct {
	vcnt, ecnt int
	e          []Edge
	id         []int
}

func (g *Graph) readGraph() {
	var n int64
	fmt.Scan(&n)
	g.e = make([]Edge, 2*n-2)
	g.id = make([]int, n+1)

	for i := int64(0); i < n-1; i++ {
		var x, y, c int64
		fmt.Scan(&x, &y, &c)
		g.e[2*i] = Edge{s: x, g: y, c: c}
		g.e[2*i+1] = Edge{s: y, g: x, c: c}
	}
	g.vcnt = int(n)
	g.ecnt = 2*int(n) - 2

	sort.Slice(g.e, func(i, j int) bool {
		if g.e[i].s != g.e[j].s {
			return g.e[i].s < g.e[j].s
		}
		return g.e[i].g < g.e[j].g
	})

	p := 0
	for i := 0; i < g.vcnt; i++ {
		for p < g.ecnt && g.e[p].s < int64(i) {
			p++
		}
		g.id[i] = p
	}
	g.id[g.vcnt] = g.ecnt // sentinel
}

var tyokkeitemp []int

func tyokkeidfs(g *Graph, s int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if tyokkeitemp[g.e[i].g] == 0 {
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + int(g.e[i].c)
			tyokkeidfs(g, int(g.e[i].g))
		}
	}
}

func tyokkei(g *Graph) int {
	tyokkeitemp = make([]int, g.vcnt+10)
	tyokkeitemp[0] = 1
	tyokkeidfs(g, 0)

	M, Mi := 0, 0
	for i := 0; i < g.vcnt; i++ {
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
			Mi = i
		}
	}

	for i := 0; i < g.vcnt; i++ {
		tyokkeitemp[i] = 0
	}
	tyokkeitemp[Mi] = 1
	tyokkeidfs(g, Mi)

	for i := 0; i < g.vcnt; i++ {
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
		}
	}
	return M - 1
}

func main() {
	g := Graph{}
	g.readGraph()
	fmt.Println(tyokkei(&g))
}

// <END-OF-CODE>

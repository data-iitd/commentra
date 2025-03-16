package main

import (
	"fmt"
	"sort"
)

type edge struct {
	s, g, c int
}

type graph struct {
	vcnt, ecnt int
	e          []edge
	id         []int
}

var g graph

func esort(a, b interface{}) int {
	p := a.(edge)
	q := b.(edge)
	if p.s < q.s {
		return -1
	}
	if p.s > q.s {
		return 1
	}
	if p.g < q.g {
		return -1
	}
	return 1
}

func readgraph() {
	var n int
	fmt.Scan(&n)
	g.e = make([]edge, 2*n-2)
	g.id = make([]int, n+1)
	for i := 0; i < n-1; i++ {
		var x, y, c int
		fmt.Scan(&x, &y, &c)
		g.e[2*i] = edge{x, y, c}
		g.e[2*i+1] = edge{y, x, c}
	}
	g.vcnt = n
	g.ecnt = 2*n - 2
	sort.Slice(g.e, func(i, j int) bool {
		return esort(g.e[i], g.e[j]) < 0
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

var tyokkeitemp []int

func tyokkeidfs(s int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if tyokkeitemp[g.e[i].g] == 0 {
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
			tyokkeidfs(g.e[i].g)
		}
	}
}

func tyokkei() int {
	tyokkeitemp = make([]int, g.vcnt+10)
	tyokkeitemp[0] = 1
	tyokkeidfs(0)
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
	tyokkeidfs(Mi)
	for i := 0; i < g.vcnt; i++ {
		if M < tyokkeitemp[i] {
			M = tyokkeitemp[i]
		}
	}
	return M - 1
}

func main() {
	readgraph()
	fmt.Println(tyokkei())
}



package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Edge struct {
	s, g, c int
}

type Graph struct {
	vcnt, ecnt int
	e           []Edge
	id          []int
}

func esort(a, b interface{}) bool {
	ea := a.(Edge)
	eb := b.(Edge)
	if ea.s < eb.s {
		return true
	} else if ea.s > eb.s {
		return false
	} else if ea.g < eb.g {
		return true
	} else {
		return false
	}
}

func readgraph() Graph {
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	g := Graph{
		vcnt: n,
		ecnt: 2*n - 2,
		e:    make([]Edge, 2*n-2),
		id:   make([]int, n+1),
	}
	for i := 0; i < n-1; i++ {
		var x, y, c int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &x, &y, &c)
		g.e[2*i] = Edge{x, y, c}
		g.e[2*i+1] = Edge{y, x, c}
	}
	sort.Slice(g.e, func(i, j int) bool {
		return esort(g.e[i], g.e[j])
	})
	p := 0
	for i := 0; i < n; i++ {
		for p < g.ecnt && g.e[p].s < i {
			p++
		}
		g.id[i] = p
	}
	g.id[n] = g.ecnt
	return g
}

func tyokkeidfs(s int, dist []int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if dist[g.e[i].g] == 0 {
			dist[g.e[i].g] = dist[s] + g.e[i].c
			tyokkeidfs(g.e[i].g, dist)
		}
	}
}

func tyokkei(g Graph) int {
	dist := make([]int, g.vcnt+10)
	dist[0] = 1
	tyokkeidfs(0, dist)
	M := 0
	Mi := 0
	for i := 0; i < g.vcnt; i++ {
		if dist[i] > M {
			M = dist[i]
			Mi = i
		}
	}
	for i := 0; i < g.vcnt; i++ {
		dist[i] = 0
	}
	dist[Mi] = 1
	tyokkeidfs(Mi, dist)
	for i := 0; i < g.vcnt; i++ {
		if dist[i] > M {
			M = dist[i]
		}
	}
	return M - 1
}

func main() {
	g := readgraph()
	fmt.Println(tyokkei(g))
}



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

func (g *Graph) readGraph() {
	// Adapted from the given C code
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	g.e = make([]Edge, 2*n-2)
	g.id = make([]int, n)
	for i := 0; i < n-1; i++ {
		var x, y, c int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &x, &y, &c)
		g.e[2*i] = Edge{x, y, c}
		g.e[2*i+1] = Edge{y, x, c}
	}
	g.vcnt = n
	g.ecnt = 2 * n - 2
	sort.Slice(g.e, func(i, j int) bool {
		if g.e[i].s < g.e[j].s {
			return true
		} else if g.e[i].s > g.e[j].s {
			return false
		} else if g.e[i].g < g.e[j].g {
			return true
		} else {
			return false
		}
	})
	p := 0
	for i := 0; i < g.vcnt; i++ {
		for p < g.ecnt && g.e[p].s < i {
			p++
		}
		g.id[i] = p
	}
	g.id[g.vcnt] = g.ecnt // Add a sentinel value
}

func (g *Graph) tyokkei() int {
	// Adapted from the given C code
	typeokkeitemp := make([]int, g.vcnt+10)
	typeokkeitemp[0] = 1
	var dfs func(int)
	dfs = func(s int) {
		for i := g.id[s]; i < g.id[s+1]; i++ {
			if typeokkeitemp[g.e[i].g] == 0 {
				typeokkeitemp[g.e[i].g] = typeokkeitemp[s] + g.e[i].c
				dfs(g.e[i].g)
			}
		}
	}
	dfs(0)
	max := 0
	maxIndex := 0
	for i := 0; i < g.vcnt; i++ {
		if typeokkeitemp[i] > max {
			max = typeokkeitemp[i]
			maxIndex = i
		}
	}
	for i := 0; i < g.vcnt; i++ {
		typeokkeitemp[i] = 0
	}
	typeokkeitemp[maxIndex] = 1
	dfs(maxIndex)
	for i := 0; i < g.vcnt; i++ {
		if typeokkeitemp[i] > max {
			max = typeokkeitemp[i]
		}
	}
	return max - 1
}

func main() {
	g := Graph{}
	g.readGraph()
	fmt.Println(g.tyokkei())
}


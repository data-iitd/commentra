package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

//<START-OF-CODE>

type Edge struct {
	s, g, c int
}

type Graph struct {
	vcnt, ecnt int
	e          [200010]Edge
	id         [100010]int
}

func readgraph() {
	//<START-OF-READGRAPH>
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		x, y, c := strings.Split(scanner.Text(), " "), 0, 0
		x[0], x[1], x[2] = x[0][0], x[1][0], x[2][0]
		x[0], x[1], x[2] = int(x[0])-1, int(x[1])-1, int(x[2])
		y[0], y[1], y[2] = y[0][0], y[1][0], y[2][0]
		y[0], y[1], y[2] = int(y[0])-1, int(y[1])-1, int(y[2])
		c, _ = strconv.Atoi(x[2])
		g.e[2*i].s, g.e[2*i].g, g.e[2*i].c = x[0], y[0], c
		g.e[2*i+1].s, g.e[2*i+1].g, g.e[2*i+1].c = y[0], x[0], c
		g.e[2*i].s, g.e[2*i+1].s = g.e[2*i+1].s, g.e[2*i].s
		g.e[2*i].g, g.e[2*i+1].g = g.e[2*i+1].g, g.e[2*i].g
		g.e[2*i].c, g.e[2*i+1].c = g.e[2*i+1].c, g.e[2*i].c
	}
	g.vcnt = n
	g.ecnt = 2*n - 2
	sort.Slice(g.e[:g.ecnt], func(i, j int) bool {
		if g.e[i].s < g.e[j].s {
			return true
		}
		if g.e[i].s > g.e[j].s {
			return false
		}
		if g.e[i].g < g.e[j].g {
			return true
		}
		return false
	})
	p := 0
	for i := 0; i < g.vcnt; i++ {
		for p < g.ecnt && g.e[p].s < i {
			p++
		}
		g.id[i] = p
	}
	g.id[g.vcnt] = g.ecnt //番兵
	//<END-OF-READGRAPH>
}

//<START-OF-TYOKKEI>
func tyokkeidfs(s int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if tyokkeitemp[g.e[i].g] == 0 {
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
			tyokkeidfs(g.e[i].g)
		}
	}
}

func tyokkei() int {
	tyokkeitemp := make([]int, g.vcnt+10)
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
		M = max(M, tyokkeitemp[i])
	}
	return M - 1
}

//<END-OF-TYOKKEI>

func main() {
	readgraph()
	fmt.Println(tyokkei())
}

//
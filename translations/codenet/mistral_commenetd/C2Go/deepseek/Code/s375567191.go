package main

import (
	"fmt"
)

const (
	MAX  = 101
	WHITE = 0
	BLACK = 2
	GRAY  = 1
)

var (
	time int
	n    int
	g    [MAX][MAX]int
	d    [MAX]int
	f    [MAX]int
	color [MAX]int
)

func visit(u int) {
	i := 0

	color[u] = GRAY
	d[u] = time + 1

	for ; i < n; i++ {
		if g[u][i] == 0 {
			continue
		}
		if color[i] == WHITE {
			visit(i)
		}
	}

	color[u] = BLACK
	f[u] = time + 1
}

func dfs() {
	i := 0
	time = 0

	for ; i < n; i++ {
		if color[i] == WHITE {
			visit(i)
		}
	}

	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var i, j, x, y, z int

	fmt.Scan(&n)

	for i = 0; i < n; i++ {
		fmt.Scan(&x, &y)

		for j = 0; j < y; j++ {
			fmt.Scan(&z)
			g[x-1][z-1] = 1
		}
	}

	dfs()
}


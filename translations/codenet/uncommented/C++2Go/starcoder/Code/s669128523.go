package main

import (
	"fmt"
)

const (
	WHITE = 0
	GRAY  = 1
	BLACK = 2
)

var (
	n   int
	M   [100][100]
	color [100]
	d [100]
	f [100]
	tt int
)

func dfs_visit(u int) {
	var v int
	color[u] = GRAY
	d[u] = tt + 1
	for v = 0; v < n; v++ {
		if M[u][v] == 0 {
			continue
		}
		if color[v] == WHITE {
			dfs_visit(v)
		}
	}
	color[u] = BLACK
	f[u] = tt + 1
}

func dfs() {
	var u int
	for i := 0; i < n; i++ {
		color[i] = WHITE
	}
	tt = 0
	for u = 0; u < n; u++ {
		if color[u] == WHITE {
			dfs_visit(u)
		}
	}
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var k, u, v int
	fmt.Scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0
		}
	}
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d\n", &u, &k)
		u--
		for j := 0; j < k; j++ {
			fmt.Scanf("%d\n", &v)
			v--
			M[u][v] = 1
		}
	}
	dfs()
}


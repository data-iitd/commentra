package main

import (
	"fmt"
)

const (
	N     = 100
	WHITE = 0
	GREY  = 1
	BLACK = 2
)

var (
	M    [N][N]int
	n    int
	color [N]int
	d    [N]int
	f    [N]int
	tt   int
)

func dfsVisit(u int) {
	v := 0
	color[u] = GREY
	d[u] = tt
	tt++
	for v = 0; v < n; v++ {
		if M[u][v] == 0 {
			continue
		}
		if color[v] == WHITE {
			dfsVisit(v)
		}
	}
	color[u] = BLACK
	f[u] = tt
	tt++
}

func dfs() {
	u := 0
	for i := 0; i < n; i++ {
		color[i] = WHITE
	}
	tt = 0

	for u = 0; u < n; u++ {
		if color[u] == WHITE {
			dfsVisit(u)
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var k, u, v int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0
		}
	}

	for i := 0; i < n; i++ {
		fmt.Scan(&u, &k)
		u--
		for j := 0; j < k; j++ {
			fmt.Scan(&v)
			v--
			M[u][v] = 1
		}
	}

	dfs()
}


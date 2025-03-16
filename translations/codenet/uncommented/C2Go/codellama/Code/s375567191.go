package main

import "fmt"

const (
	WHITE = 0
	BLACK = 2
	GRAY  = 1
	MAX   = 101
)

var (
	n, time int
	g       [MAX][MAX]int
	d, f    [MAX]int
	color   [MAX]int
)

func visit(u int) {
	var i int

	color[u] = GRAY
	d[u] = time
	time++

	for i = 0; i < n; i++ {
		if g[u][i] == 0 {
			continue
		}
		if color[i] == WHITE {
			visit(i)
		}
	}

	color[u] = BLACK
	f[u] = time
	time++
}

func dfs() {
	var i int

	time = 0

	for i = 0; i < n; i++ {
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

	fmt.Scanf("%d", &n)

	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &x, &y)
		for j = 0; j < y; j++ {
			fmt.Scanf("%d", &z)
			g[x-1][z-1] = 1
		}
	}

	dfs()
}


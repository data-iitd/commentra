package main

import (
	"fmt"
)

const MAX = 101
const WHITE = 0
const BLACK = 2
const GRAY = 1

var time, n int
var g [MAX][MAX]int
var d [MAX]int
var f [MAX]int
var color [MAX]int

func visit(u int) {
	color[u] = GRAY
	time++
	d[u] = time

	for i := 0; i < n; i++ {
		if g[u][i] == 0 {
			continue
		}
		if color[i] == WHITE {
			visit(i)
		}
	}

	color[u] = BLACK
	time++
	f[u] = time
}

func dfs() {
	time = 0

	for i := 0; i < n; i++ {
		if color[i] == WHITE {
			visit(i)
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var x, y, z int

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&x, &y)
		for j := 0; j < y; j++ {
			fmt.Scan(&z)
			g[x-1][z-1] = 1
		}
	}

	dfs()
}

// <END-OF-CODE>

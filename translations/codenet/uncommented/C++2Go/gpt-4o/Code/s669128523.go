package main

import (
	"fmt"
)

const N = 100
const WHITE = 0
const GRAY = 1
const BLACK = 2

var M [N][N]int
var n int
var color [N]int
var d [N]int
var f [N]int
var tt int

func dfsVisit(u int) {
	color[u] = GRAY
	tt++
	d[u] = tt
	for v := 0; v < n; v++ {
		if M[u][v] == 0 {
			continue
		}
		if color[v] == WHITE {
			dfsVisit(v)
		}
	}
	color[u] = BLACK
	tt++
	f[u] = tt
}

func dfs() {
	for i := 0; i < n; i++ {
		color[i] = WHITE
	}
	tt = 0

	for u := 0; u < n; u++ {
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

// <END-OF-CODE>

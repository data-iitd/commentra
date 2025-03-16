package main

import (
	"fmt"
)

const (
	INF  = 100000
	MAX  = 101
	NIL  = -6
	WHITE = 0
	GRAY  = 1
	BLACK = 2
)

var G [MAX][MAX]int
var n int

func prim() {
	var i, j int
	var d [MAX]int
	var pi [MAX]int
	var color [MAX]int
	var min, u, v, sum int

	for i = 0; i < n; i++ {
		d[i] = INF
		pi[i] = NIL
		color[i] = WHITE
	}

	d[0] = 0

	for {
		min = INF
		u = NIL
		for i = 0; i < n; i++ {
			if color[i] != BLACK && d[i] < min {
				min = d[i]
				u = i
			}
		}
		if u == NIL {
			break
		}
		color[u] = BLACK
		for v = 0; v < n; v++ {
			if color[v] != BLACK && G[u][v] != INF {
				if d[v] > G[u][v] {
					d[v] = G[u][v]
					pi[v] = u
					color[v] = GRAY
				}
			}
		}
	}
	for i = 0; i < n; i++ {
		if pi[i] != NIL {
			sum += G[i][pi[i]]
		}
	}
	fmt.Println(sum)
}

func main() {
	var e int

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Scan(&e)
			if e == -1 {
				G[i][j] = INF
			} else {
				G[i][j] = e
			}
		}
	}

	prim()
}

// <END-OF-CODE>

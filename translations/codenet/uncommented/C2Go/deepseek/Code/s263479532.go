package main

import (
	"fmt"
)

const (
	MAX  = 100
	INF  = 999999
	NIL  = -1
	WHITE = 0
	BLACK = 2
)

func prim() int {
	var n int
	var G [MAX][MAX]int

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Scan(&G[i][j])
		}
	}

	d := make([]int, n)
	pi := make([]int, n)
	color := make([]int, n)
	sum := 0

	for u := 0; u < n; u++ {
		d[u] = INF
		pi[u] = NIL
		color[u] = WHITE
	}

	d[0] = 0
	for {
		mincost := INF
		var u int

		for i := 0; i < n; i++ {
			if color[i] != BLACK && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}

		if mincost == INF {
			break
		}

		color[u] = BLACK

		for v := 0; v < n; v++ {
			if color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1 {
				pi[v] = u
				d[v] = G[u][v]
			}
		}
	}

	for i := 0; i < n; i++ {
		if d[i] != INF {
			sum += d[i]
		}
	}

	return sum
}

func main() {
	fmt.Println(prim())
}


package main

import (
	"fmt"
	"math"
)

const (
	MAX = 100
	INF = math.MaxInt32
	NIL = -1
	WHITE = 0
	BLACK = 2
)

func prim(n int, G [][]int) int {
	var u, mincost, sum int
	d := make([]int, n)
	pi := make([]int, n)
	color := make([]int, n)

	for u := 0; u < n; u++ {
		d[u] = INF
		pi[u] = NIL
		color[u] = WHITE
	}

	d[0] = 0
	for {
		mincost = INF
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
	var n int
	fmt.Scan(&n)
	G := make([][]int, n)
	for i := 0; i < n; i++ {
		G[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&G[i][j])
		}
	}

	fmt.Println(prim(n, G))
}

// <END-OF-CODE>

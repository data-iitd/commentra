package main

import "fmt"

const (
	MAX = 100
	INF = 999999
	NIL = -1
	WHITE = 0
	BLACK = 2
)

func prim() int {
	var u, i, v, mincost, d [MAX]int
	var pi [MAX]int
	var color [MAX]int
	var sum int

	for i = 0; i < MAX; i++ {
		d[i] = INF
		pi[i] = NIL
		color[i] = WHITE
	}

	d[0] = 0
	for {
		mincost = INF
		for i = 0; i < MAX; i++ {
			if color[i] != BLACK && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}
		if mincost == INF {
			break
		}
		color[u] = BLACK
		for v = 0; v < MAX; v++ {
			if color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1 {
				pi[v] = u
				d[v] = G[u][v]
			}
		}
	}

	for i = 0; i < MAX; i++ {
		if d[i] != INF {
			sum += d[i]
		}
	}

	return sum
}

func main() {
	var i, j int

	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			fmt.Scan(&G[i][j])
		}
	}

	fmt.Println(prim())
}


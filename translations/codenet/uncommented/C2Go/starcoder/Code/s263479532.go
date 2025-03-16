package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	G := make([][]int, n)
	for i := 0; i < n; i++ {
		G[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scanf("%d", &G[i][j])
		}
	}
	fmt.Printf("%d\n", prim(G, n))
}

func prim(G [][]int, n int) int {
	var u, v, mincost, sum int
	d := make([]int, n)
	pi := make([]int, n)
	color := make([]int, n)
	for u = 0; u < n; u++ {
		d[u] = 999999
		pi[u] = -1
		color[u] = 0
	}
	d[0] = 0
	for {
		mincost = 999999
		for u = 0; u < n; u++ {
			if color[u] == 0 && d[u] < mincost {
				mincost = d[u]
				v = u
			}
		}
		if mincost == 999999 {
			break
		}
		color[v] = 1
		for v = 0; v < n; v++ {
			if color[v] == 0 && G[v][u] < d[v] && G[v][u]!= -1 {
				pi[v] = u
				d[v] = G[v][u]
			}
		}
	}
	for i := 0; i < n; i++ {
		if d[i]!= 999999 {
			sum += d[i]
		}
	}
	return sum
}




package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

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

func prim(n int, G [][]int) int {
	d := make([]int, n)
	pi := make([]int, n)
	color := make([]int, n)
	for i := 0; i < n; i++ {
		d[i] = 100000000
		pi[i] = -1
		color[i] = 0
	}
	d[0] = 0
	for {
		mincost := 100000000
		var u int
		for i := 0; i < n; i++ {
			if color[i]!= 2 && d[i] < mincost {
				mincost = d[i]
				u = uint(i)
			}
		}
		if mincost == 100000000 {
			break
		}
		color[u] = 2
		for v := 0; v < n; v++ {
			if color[v]!= 2 && G[u][v] < d[v] && G[u][v]!= -1 {
				pi[v] = int(u)
				d[v] = G[u][v]
			}
		}
	}
	sum := 0
	for i := 0; i < n; i++ {
		if d[i]!= 100000000 {
			sum += d[i]
		}
	}
	return sum
}


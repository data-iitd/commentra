
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	MAX = 100
	INF = 999999
	NIL = -1
	WHITE = 0
	BLACK = 2
)

func main() {
	var n int
	var G [MAX][MAX]int
	var i, j int
	var u, v, mincost, d, pi, color, sum int

	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}

	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			if scanner.Scan() {
				G[i][j], _ = strconv.Atoi(scanner.Text())
			}
		}
	}

	for u = 0; u < n; u++ {
		d = INF
		pi[u] = NIL
		color[u] = WHITE
	}

	d[0] = 0
	for {
		mincost = INF
		for i = 0; i < n; i++ {
			if color[i]!= BLACK && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}

		if mincost == INF {
			break
		}

		color[u] = BLACK

		for v = 0; v < n; v++ {
			if color[v]!= BLACK && G[u][v] < d[v] && G[u][v]!= -1 {
				pi[v] = u
				d[v] = G[u][v]
			}
		}
	}

	for i = 0; i < n; i++ {
		if d[i]!= INF {
			sum += d[i]
		}
	}

	fmt.Println(sum)
	// 
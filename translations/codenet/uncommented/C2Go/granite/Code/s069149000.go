
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	INF = 100000
	MAX = 101
	NIL = -6
	WHITE = 0
	GRAY = 1
	BLACK = 2
)

var (
	G [MAX][MAX]int
	n int
	d [MAX]int
	pi [MAX]int
	color [MAX]int
)

func init() {
	for i := 0; i < MAX; i++ {
		d[i] = INF
		pi[i] = NIL
		color[i] = WHITE
	}
}

func prim() {
	var i, j, min, u, v, sum int

	d[0] = 0

	for {
		min = INF
		u = NIL
		for i = 0; i < n; i++ {
			if color[i]!= BLACK && d[i] < min {
				min = d[i]
				u = i
			}
		}
		if u == NIL {
			break
		}
		color[u] = BLACK
		for v = 0; v < n; v++ {
			if color[v]!= BLACK && G[u][v]!= INF {
				if d[v] > G[u][v] {
					d[v] = G[u][v]
					pi[v] = u
					color[v] = GRAY
				}
			}
		}
	}
	for i = 0; i < n; i++ {
		if pi[i]!= NIL {
			sum += G[i][pi[i]]
		}
	}
	fmt.Println(sum)
}

func main() {
	var e int

	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if scanner.Scan() {
				e, _ = strconv.Atoi(scanner.Text())
				if e == -1 {
					G[i][j] = INF
				} else {
					G[i][j] = e
				}
			}
		}
	}
	prim()
	// 
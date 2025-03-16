package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var i, j int
	var e int
	var G [101][101]int
	var d [101]int
	var pi [101]int
	var color [101]int
	var min int
	var u, v int
	var sum int

	fmt.Scanf("%d", &n)

	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			fmt.Scanf("%d", &e)
			if e == -1 {
				G[i][j] = 100000
			} else {
				G[i][j] = e
			}
		}
	}

	for i = 0; i < n; i++ {
		d[i] = 100000
		pi[i] = -1
		color[i] = 0
	}

	d[0] = 0

	for {
		min = 100000
		u = -1
		for i = 0; i < n; i++ {
			if color[i]!= 2 && d[i] < min {
				min = d[i]
				u = i
			}
		}
		if u == -1 {
			break
		}
		color[u] = 2
		for v = 0; v < n; v++ {
			if color[v]!= 2 && G[u][v]!= 100000 {
				if d[v] > G[u][v] {
					d[v] = G[u][v]
					pi[v] = u
					color[v] = 1
				}
			}
		}
	}
	for i = 0; i < n; i++ {
		if pi[i]!= -1 {
			sum += G[i][pi[i]]
		}
	}
	fmt.Printf("%d\n", sum)
}


package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, i, j, x, y, z int
	var g [101][101]int
	var d [101]int
	var f [101]int
	var color [101]int

	fmt.Scanf("%d", &n)

	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &x, &y)
		for j = 0; j < y; j++ {
			fmt.Scanf("%d", &z)
			g[x-1][z-1] = 1
		}
	}

	for i = 0; i < n; i++ {
		color[i] = 0
	}

	time := 0
	for i = 0; i < n; i++ {
		if color[i] == 0 {
			visit(i)
		}
	}

	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func visit(u int) {
	var i int
	color[u] = 1
	d[u] = time
	time++

	for i = 0; i < n; i++ {
		if g[u][i] == 0 {
			continue
		}
		if color[i] == 0 {
			visit(i)
		}
	}

	color[u] = 2
	f[u] = time
	time++
}


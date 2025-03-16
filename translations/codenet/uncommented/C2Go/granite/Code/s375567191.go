
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX  = 101
	WHITE = 0
	BLACK = 2
	GRAY  = 1
)

var (
	time int
	n    int
	g    [MAX][MAX]
	d    [MAX]int
	f    [MAX]int
	color [MAX]int
)

func visit(u int) {
	var i int

	color[u] = GRAY
	d[u] = ++time

	for i = 0; i < n; i++ {
		if g[u][i] == 0 {
			continue
		}
		if color[i] == WHITE {
			visit(i)
		}
	}

	color[u] = BLACK
	f[u] = ++time
}

func dfs() {
	var i int

	time = 0

	for i = 0; i < n; i++ {
		if color[i] == WHITE {
			visit(i)
		}
	}

	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var i, j, x, y, z int

	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		fmt.Sscanf(scanner.Text(), "%d", &n)
	}

	for i = 0; i < n; i++ {
		if scanner.Scan() {
			fmt.Sscanf(scanner.Text(), "%d %d", &x, &y)
		}
		for j = 0; j < y; j++ {
			if scanner.Scan() {
				fmt.Sscanf(scanner.Text(), "%d", &z)
			}
			g[x-1][z-1] = 1
		}
	}

	dfs()
	// 
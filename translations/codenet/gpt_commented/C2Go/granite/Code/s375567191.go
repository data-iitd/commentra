
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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
	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		text := scanner.Text()
		fields := len(text)
		if fields == 0 {
			continue
		}
		if fields == 1 {
			n, _ = strconv.Atoi(text)
			continue
		}
		if fields == 2 {
			x, _ = strconv.Atoi(text)
			continue
		}
		y, _ = strconv.Atoi(text)
		for j = 0; j < y; j++ {
			scanner.Scan()
			z, _ = strconv.Atoi(scanner.Text())
			g[x-1][z-1] = 1
		}
	}
	dfs()
}


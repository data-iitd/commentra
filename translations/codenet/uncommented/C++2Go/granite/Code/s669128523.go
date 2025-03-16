
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	WHITE = 0
	GRAY  = 1
	BLACK = 2
)

var (
	M     = make([][]int, 100)
	color = make([]int, 100)
	d     = make([]int, 100)
	f     = make([]int, 100)
	tt    int
)

func init() {
	for i := 0; i < 100; i++ {
		M[i] = make([]int, 100)
	}
}

func dfsVisit(u int) {
	var v int
	color[u] = GRAY
	d[u] = ++tt
	for v = 0; v < n; v++ {
		if M[u][v] == 0 {
			continue
		}
		if color[v] == WHITE {
			dfsVisit(v)
		}
	}
	color[u] = BLACK
	f[u] = ++tt
}

func dfs() {
	var u int
	for i := 0; i < n; i++ {
		color[i] = WHITE
	}
	tt = 0

	for u = 0; u < n; u++ {
		if color[u] == WHITE {
			dfsVisit(u)
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var n, k, v int
	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		text := scanner.Text()
		fields := len(fields)
		switch fields {
		case 0:
			continue
		case 1:
			n, _ = strconv.Atoi(text)
		case 2:
			k, _ = strconv.Atoi(text)
		default:
			v, _ = strconv.Atoi(text)
			M[n-1][v-1] = 1
		}
	}
	dfs()
}



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

func dfsVisit(u int) {
	var v int
	color[u] = GRAY
	d[u] = tt + 1
	for v = 0; v < n; v++ {
		if M[u][v] == 0 {
			continue
		}
		if color[v] == WHITE {
			dfsVisit(v)
		}
	}
	color[u] = BLACK
	f[u] = tt + 1
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
	data, err := os.Open(os.Args[1])
	if err!= nil {
		panic(err)
	}
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		text := scanner.Text()
		fields := len(text)
		if fields == 0 {
			continue
		}
		if fields == 1 {
			n, err = strconv.Atoi(text)
			if err!= nil {
				panic(err)
			}
			for i := 0; i < n; i++ {
				M[i] = make([]int, n)
			}
			continue
		}
		fields = len(fields)
		if fields < 3 {
			continue
		}
		u, err := strconv.Atoi(fields[0])
		if err!= nil {
			panic(err)
		}
		k, err := strconv.Atoi(fields[1])
		if err!= nil {
			panic(err)
		}
		for i := 0; i < k; i++ {
			v, err := strconv.Atoi(fields[i+2])
			if err!= nil {
				panic(err)
			}
			M[u-1][v-1] = 1
		}
	}
	dfs()
}


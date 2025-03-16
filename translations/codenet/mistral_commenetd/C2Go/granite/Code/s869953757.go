
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	M = 100
	whi = 0
	gra = 1
	bla = 2
)

var (
	n int
	T [M][M]int
	color [M]int
	d [M]int
	Q [M]int
	head int
	tail int
)

func enqueue(x int) {
	Q[tail] = x
	tail = (tail + 1) % M
}

func dequeue() int {
	x := Q[head]
	head = (head + 1) % M
	return x
}

func bfs(s int) {
	i, u, v int
	for i = 0; i < n; i++ {
		color[i] = whi
		d[i] = 1000000
	}
	color[s] = gra
	d[s] = 0
	enqueue(s)
	for head!= tail {
		u = dequeue()
		for v = 0; v < n; v++ {
			if T[u][v] == 1 && color[v] == whi {
				color[v] = gra
				d[v] = d[u] + 1
				enqueue(v)
			}
		}
		color[u] = bla
	}
}

func main() {
	var i, j int
	var u, k, v int
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			T[i][j] = 0
		}
	}
	for i = 0; i < n; i++ {
		if scanner.Scan() {
			u, _ = strconv.Atoi(scanner.Text())
		}
		u--
		if scanner.Scan() {
			k, _ = strconv.Atoi(scanner.Text())
		}
		for j = 0; j < k; j++ {
			if scanner.Scan() {
				v, _ = strconv.Atoi(scanner.Text())
			}
			v--
			T[u][v] = 1
		}
	}
	bfs(0)
	for i = 0; i < n; i++ {
		if d[i] == 1000000 {
			d[i] = -1
		}
		fmt.Printf("%d %d\n", i+1, d[i])
	}
}


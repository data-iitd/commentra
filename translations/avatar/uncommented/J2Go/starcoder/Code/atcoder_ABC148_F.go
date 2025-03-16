package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	u, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	v, _ := strconv.Atoi(sc.Text())
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0)
	}
	for i := 0; i < N-1; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}
	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = 1000000000
	}
	d[u] = 0
	dfs(u, d, edges)
	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = 1000000000
	}
	e[v] = 0
	dfs(v, e, edges)
	q := -1
	for i := 0; i < N; i++ {
		if d[i] < e[i] {
			if e[i] > q {
				q = e[i]
			}
		}
	}
	if q <= 0 {
		fmt.Println(0)
	} else {
		fmt.Println(q - 1)
	}
}

func dfs(u int, d []int, edges [][]int) {
	for _, nu := range edges[u] {
		if d[nu] == 1000000000 {
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}


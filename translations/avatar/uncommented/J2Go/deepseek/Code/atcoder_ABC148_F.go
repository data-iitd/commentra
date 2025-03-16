package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	var N int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	u := parseInt(sc) - 1
	v := parseInt(sc) - 1

	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = []int{}
	}

	for i := 0; i < N-1; i++ {
		a := parseInt(sc) - 1
		b := parseInt(sc) - 1
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}

	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = int(^uint(0) >> 1)
	}
	d[u] = 0
	dfs(u, d, edges)

	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = int(^uint(0) >> 1)
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

func parseInt(sc *bufio.Scanner) int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func dfs(u int, d []int, edges [][]int) {
	for _, nu := range edges[u] {
		if d[nu] == int(^uint(0)>>1) {
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}


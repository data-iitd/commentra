package main

import (
	"fmt"
	"math"
)

func main() {
	var N, u, v int
	fmt.Scan(&N, &u, &v)
	u-- // Convert to 0-based index
	v-- // Convert to 0-based index

	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = []int{}
	}

	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to 0-based index
		b-- // Convert to 0-based index
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}

	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = math.MaxInt32
	}
	d[u] = 0
	dfs(u, d, edges)

	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = math.MaxInt32
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
		if d[nu] == math.MaxInt32 {
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}

// <END-OF-CODE>

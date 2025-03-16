package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	edges := make([][]int, N)
	degs := make([]int, N)
	parity := make([]int, N)
	flag := make([]bool, N)
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
		degs[a-1]++
		degs[b-1]++
	}
	if M%2 != 0 {
		fmt.Println(-1)
		return
	}
	Q := make([][2]int, 0, N)
	for i, d := range degs {
		Q = append(Q, [2]int{d, i})
	}
	sort.Slice(Q, func(i, j int) bool {
		return Q[i][0] > Q[j][0]
	})
	for len(Q) > 0 {
		d, u := Q[0][0], Q[0][1]
		Q = Q[1:]
		if flag[u] {
			continue
		}
		flag[u] = true
		for i, v := range edges[u] {
			edges[v] = append(edges[v][:i], edges[v][i+1:]...)
			if parity[u] != 0 && i == 0 {
				fmt.Println(u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Println(v+1, u+1)
				parity[v] = 1 - parity[v]
			}
			degs[v]--
			Q = append(Q, [2]int{degs[v], v})
		}
	}
}


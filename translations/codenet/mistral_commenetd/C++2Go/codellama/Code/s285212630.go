package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	N int
	G [100000][]int
	U [22][100000]int
	R [100000]int
	L [100000]int64
)

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		G[a] = append(G[a], b)
	}
	dfs(1, 0, 0)
	fmt.Println(L[1])
}

func dfs(u, p, d int) {
	U[0][u] = p
	R[u] = d
	for _, v := range G[u] {
		if v != p {
			dfs(v, u, d+1)
			U[0][v] = u
			R[v] = d + 1
		}
	}
}


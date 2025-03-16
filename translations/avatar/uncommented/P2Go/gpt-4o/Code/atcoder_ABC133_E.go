package main

import (
	"fmt"
	"os"
)

var graph [][]int
var mod int64 = 1_000_000_007

func dfs(fro, to, f int) int64 {
	caseNum := int64(f)
	colorNum := int64(K - 1)
	if f == K {
		colorNum = int64(K - 2)
	}
	for _, u := range graph[fro] {
		if u == to {
			continue
		}
		pat := dfs(u, fro, int(colorNum))
		if pat == 0 {
			caseNum = 0
			break
		}
		caseNum = (caseNum * pat) % mod
		colorNum--
	}
	return caseNum
}

var N, K int

func main() {
	fmt.Scan(&N, &K)
	graph = make([][]int, N)
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		graph[a-1] = append(graph[a-1], b-1)
		graph[b-1] = append(graph[b-1], a-1)
	}
	ans := dfs(0, -1, K)
	fmt.Println(ans)
}

// <END-OF-CODE>

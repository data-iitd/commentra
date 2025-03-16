package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	graph := make([][]int, N)
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		graph[a-1] = append(graph[a-1], b-1)
		graph[b-1] = append(graph[b-1], a-1)
	}
	mod := int(math.Pow(10, 9) + 7)
	var dfs func(fro, to, f int) int
	dfs = func(fro, to, f int) int {
		caseNum := f
		colorNum := K - 1
		if f == K {
			colorNum = K - 2
		}
		for _, u := range graph[fro] {
			if u == to {
				continue
			}
			pat := dfs(u, fro, colorNum)
			if pat == 0 {
				caseNum = 0
				break
			}
			caseNum = (caseNum * pat) % mod
			colorNum--
		}
		return caseNum
	}
	ans := dfs(0, -1, K)
	fmt.Println(ans)
}


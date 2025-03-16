package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	vis := make([]int, n+1)
	ci, cb, cc := 0, 0, 0
	g := make([][]int, n+1)
	for i := range g {
		g[i] = make([]int, 0)
	}

	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}

	for i := 1; i <= n; i++ {
		if vis[i] == 0 {
			if len(g[i]) == 0 {
				ci++
			} else {
				if dfs(i, g, vis) {
					cb++
				} else {
					cc++
				}
			}
		}
	}

	fmt.Println(ci*ci + 2*ci*(n-ci) + cc*cc + 2*cb*cc + 2*cb*cb)
}

func dfs(x int, g [][]int, vis []int) bool {
	stk := make([][2]int, 0)
	stk = append(stk, [2]int{x, 1})
	flag := true
	for len(stk) > 0 {
		u, col := stk[len(stk)-1][0], stk[len(stk)-1][1]
		stk = stk[:len(stk)-1]
		if vis[u] != 0 {
			flag = flag && (vis[u] == col)
			continue
		}
		vis[u] = col
		for _, v := range g[u] {
			stk = append(stk, [2]int{v, 3 - col})
		}
	}
	return flag
}


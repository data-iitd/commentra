package main

import (
	"container/list"
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	vis := make([]int, n+1)
	ci, cb, cc := 0, 0, 0
	g := make([][]int, n+1)

	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}

	var dfs func(int) bool
	dfs = func(x int) bool {
		stk := list.New()
		stk.PushBack(struct {
			u   int
			col int
		}{x, 1})
		flag := true

		for stk.Len() > 0 {
			element := stk.Back()
			stk.Remove(element)
			data := element.Value.(struct {
				u   int
				col int
			})
			u, col := data.u, data.col

			if vis[u] != 0 {
				flag = flag && (vis[u] == col)
				continue
			}
			vis[u] = col
			for _, i := range g[u] {
				stk.PushBack(struct {
					u   int
					col int
				}{i, 3 - col})
			}
		}
		return flag
	}

	for i := 1; i <= n; i++ {
		if vis[i] == 0 {
			if len(g[i]) == 0 {
				ci++
			} else {
				if dfs(i) {
					cb++
				} else {
					cc++
				}
			}
		}
	}

	result := ci*ci + 2*ci*(n-ci) + cc*cc + 2*cb*cc + 2*cb*cb
	fmt.Println(result)
}

// <END-OF-CODE>

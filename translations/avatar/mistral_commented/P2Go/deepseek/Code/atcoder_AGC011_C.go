package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int
	fmt.Fscan(reader, &n, &m)

	vis := make([]int, n+1)
	var ci, cb, cc int
	g := make([][]int, n+1)

	var dfs func(x int) bool
	dfs = func(x int) bool {
		stk := [][]int{}
		flag := true

		stk = append(stk, []int{x, 1})

		for len(stk) > 0 {
			u, col := stk[len(stk)-1][0], stk[len(stk)-1][1]
			stk = stk[:len(stk)-1]

			if vis[u] > 0 {
				flag = flag && (vis[u] == col)
				continue
			}

			vis[u] = col

			for _, i := range g[u] {
				stk = append(stk, []int{i, 3 - col})
			}
		}

		return flag
	}

	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscan(reader, &u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
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

	fmt.Fprintln(writer, ci*ci+2*ci*(n-ci)+cc*cc+2*cb*cc+2*cb*cb)
}

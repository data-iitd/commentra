
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

var (
	readWriter = bufio.NewReadWriter(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	outputWriter = bufio.NewWriter(os.Stdout)
)

func main() {
	var n, m int
	fmt.Fscanf(readWriter, "%d %d\n", &n, &m)
	vis, ci, cb, cc := make([]int, n+1), 0, 0, 0
	g := make([][]int, n+1)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscanf(readWriter, "%d %d\n", &u, &v)
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
	fmt.Fprintf(outputWriter, "%d %d %d\n", ci, cb, cc)
	outputWriter.Flush()
}

func dfs(x int) bool {
	stk := make([]int, 0)
	flag := true
	stk = append(stk, x)
	stk = append(stk, 1)
	for len(stk) > 0 {
		u, col := stk[len(stk)-2], stk[len(stk)-1]
		stk = stk[:len(stk)-2]
		if vis[u]!= 0 {
			flag = flag && (vis[u] == col)
			continue
		}
		vis[u] = col
		for _, i := range g[u] {
			stk = append(stk, i)
			stk = append(stk, 3-col)
		}
	}
	return flag
}


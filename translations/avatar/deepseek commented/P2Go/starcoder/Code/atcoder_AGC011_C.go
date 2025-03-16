package main

import (
	"bufio"
	"fmt"
	"os"
)

// Global variables
var (
	n, m int
	vis  [1001]int
	ci, cb, cc int
	g    [1001][]int
)

// dfs function to determine if a graph is bipartite
func dfs(x int) bool {
	stk := make([]int, 0)
	stk = append(stk, x)
	stk = append(stk, 1)
	flag := true
	for len(stk) > 0 {
		u := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		col := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		if vis[u] == 0 {
			vis[u] = col
			for _, v := range g[u] {
				stk = append(stk, v)
				stk = append(stk, 3-col)
			}
		} else {
			flag &= (vis[u] == col)
		}
	}
	return flag
}

func main() {
	// Reading the number of nodes and edges
	fmt.Scanf("%d %d\n", &n, &m)
	// Initializing visited list and counters for isolated, bipartite, and connected components
	ci, cb, cc = 0, 0, 0
	for i := 0; i <= n; i++ {
		vis[i] = 0
		g[i] = make([]int, 0)
	}
	// Constructing the graph by reading edges
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scanf("%d %d\n", &u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	// Traversing the graph to classify nodes
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
	// Calculating and printing the result based on the counts of isolated, bipartite, and connected components
	fmt.Printf("%d\n", ci*ci+2*ci*(n-ci)+cc*cc+2*cb*cc+2*cb*cb)
}


package main

import (
	"bufio"
	"fmt"
	"os"
)

// Read the number of nodes (n) and edges (m) from input
func readInput() (n, m int) {
	fmt.Fscan(os.Stdin, &n, &m)
	return
}

// Initialize visitation status and counters for isolated components, bipartite components, and non-bipartite components
var (
	vis []int
	ci  int
	cb  int
	cc  int
)

// Create an adjacency list to represent the graph
var g [][]int

// Define a depth-first search (DFS) function to check for bipartiteness
func dfs(x int) bool {
	stk := make([]int, 0)
	stk = append(stk, x)
	vis[x] = 1
	col := 1
	flag := true
	for len(stk) > 0 {
		u := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		for _, v := range g[u] {
			if vis[v] == 0 {
				stk = append(stk, v)
				vis[v] = 3 - col
				col = 3 - col
			} else {
				flag &= (vis[v] == col)
			}
		}
	}
	return flag
}

// Read edges and build the graph
func readGraph() {
	n, m := readInput()
	g = make([][]int, n+1)
	for i := 0; i < m; i++ {
		u, v := 0, 0
		fmt.Fscan(os.Stdin, &u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
}

// Iterate through all nodes to count isolated and bipartite components
func countComponents() {
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
}

// Calculate and print the final result based on the counts of components
func printResult() {
	fmt.Println(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb)
}

func main() {
	vis = make([]int, 10001)
	readGraph()
	countComponents()
	printResult()
}


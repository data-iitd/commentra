package main

import (
	"container/list"
	"fmt"
)

var (
	n, m int
	vis  []int
	ci   int
	cb   int
	cc   int
	g    [][]int
)

// DFS function to determine if a graph is bipartite
func dfs(x int) bool {
	stk := list.New()
	stk.PushBack(pair{x, 1}) // Starting DFS from node x with color 1
	flag := true

	for stk.Len() > 0 {
		element := stk.Back()
		stk.Remove(element)
		u, col := element.Value.(pair).u, element.Value.(pair).col

		if vis[u] != 0 { // If the node has been visited, check if the color is consistent
			flag = flag && (vis[u] == col)
			continue
		}
		vis[u] = col // Marking the node as visited with the current color
		for _, i := range g[u] {
			stk.PushBack(pair{i, 3 - col}) // Adding adjacent nodes to the stack with the opposite color
		}
	}
	return flag
}

type pair struct {
	u   int
	col int
}

func main() {
	fmt.Scan(&n, &m) // Reading the number of nodes and edges
	vis = make([]int, n+1)
	g = make([][]int, n+1)

	// Constructing the graph by reading edges
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		g[u] = append(g[u], v) // Adding edge u-v
		g[v] = append(g[v], u) // Adding edge v-u (undirected graph)
	}

	// Traversing the graph to classify nodes
	for i := 1; i <= n; i++ {
		if vis[i] == 0 { // If the node has not been visited
			if len(g[i]) == 0 {
				ci++ // Increment the count of isolated nodes
			} else {
				if dfs(i) {
					cb++ // Increment the count of bipartite graphs
				} else {
					cc++ // Increment the count of connected components that are not bipartite
				}
			}
		}
	}

	// Calculating and printing the result based on the counts of isolated, bipartite, and connected components
	result := ci*ci + 2*ci*(n-ci) + cc*cc + 2*cb*cc + 2*cb*cb
	fmt.Println(result)
}

// <END-OF-CODE>

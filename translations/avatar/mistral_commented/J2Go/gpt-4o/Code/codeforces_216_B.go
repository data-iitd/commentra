package main

import (
	"fmt"
)

type Main struct {
	count int
	seen  []bool
	path  int
	cycle int
	graph [][]int
}

func (m *Main) dfs(child, par int) int {
	if m.seen[child] { // Checking if the current node has already been visited.
		return m.cycle // If it has, then there is a cycle in the graph and we return 1.
	}
	m.seen[child] = true // Marking the current node as visited.

	for _, i := range m.graph[child] { // Iterating through the neighbors of the current node.
		if i != par { // Checking if the neighbor is not the parent node.
			m.count++ // Incrementing the count of edges traversed.
			if m.dfs(i, child) == m.cycle { // Recursively calling the dfs function on the neighbor.
				return m.cycle // If there is a cycle, then we return 1.
			}
		}
	}
	return m.path // If there is no cycle, then we return 0.
}

func main() {
	var m, n int
	fmt.Scan(&m, &n) // Reading the number of nodes and edges in the graph.
	ft := Main{
		graph: make([][]int, m+1), // Initializing the graph as an empty 2D slice.
		seen:  make([]bool, m+1),   // Initializing the seen array as a boolean slice of size (m+1).
	}

	for i := 0; i <= m; i++ { // Initializing the graph with empty slices for each node.
		ft.graph[i] = []int{}
	}

	for i := 0; i < n; i++ { // Reading the edges from the input and adding them to the graph.
		var x, y int
		fmt.Scan(&x, &y)
		ft.graph[x] = append(ft.graph[x], y) // Adding an edge from x to y.
		ft.graph[y] = append(ft.graph[y], x) // Adding an edge from y to x.
	}

	toremove := 0 // Initializing the toremove variable to 0.
	for i := 1; i <= m; i++ { // Iterating through all the nodes in the graph.
		if !ft.seen[i] { // If the current node has not been visited.
			ft.count = 0 // Resetting the count of edges traversed to 0.
			if ft.dfs(i, 0) == ft.cycle { // If there is a cycle in the subgraph rooted at the current node.
				if ft.count%2 == 1 { // If the number of edges traversed is odd.
					toremove++ // Increment the toremove variable.
				}
			}
		}
	}

	if (m-toremove)%2 == 1 { // Checking if the number of nodes is odd.
		toremove++ // If it is, then increment the toremove variable.
	}

	fmt.Println(toremove) // Printing the result.
}

// <END-OF-CODE>
